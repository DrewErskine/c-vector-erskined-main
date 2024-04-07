#include "vector.h"
#include <stdbool.h>
#include <string.h>

// Internal functions to manage vector capacity
static bool vec_grow(vector* vec) {
    size_t newCapacity = vec->capacity * 2;
    void** newData = realloc(vec->data, newCapacity * sizeof(void*));
    if (newData == NULL) {
        return false; // Allocation failed
    }
    vec->data = newData;
    vec->capacity = newCapacity;
    return true;
}

vector* new_vec(size_t type_size, size_t initial_size) {
    vector* vec = malloc(sizeof(vector));
    if (vec == NULL) return NULL; // Allocation failed

    vec->data = malloc(initial_size * sizeof(void*));
    if (vec->data == NULL) {
        free(vec);
        return NULL; // Allocation failed
    }

    vec->length = 0;
    vec->capacity = initial_size;
    vec->type_size = type_size;
    vec->filled_percentage = 0.0;

    return vec;
}

int vec_length(vector* vec) {
    return vec->length;
}

void vec_add(vector* vec, void* element) {
    if (vec->length == vec->capacity) {
        if (!vec_grow(vec)) return; // Failed to grow vector
    }

    vec->data[vec->length] = malloc(vec->type_size);
    memcpy(vec->data[vec->length], element, vec->type_size);
    vec->length++;
    vec->filled_percentage = (float)vec->length / vec->capacity;
}

void* vec_get(vector* vec, size_t index) {
    if (index < vec->length) {
        return vec->data[index];
    }
    return NULL; // Index out of bounds
}

void* vec_remove(vector* vec, size_t index) {
    if (index >= vec->length) return NULL; // Index out of bounds

    void* element = vec->data[index];
    for (size_t i = index; i < vec->length - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length--;
    vec->filled_percentage = (float)vec->length / vec->capacity;

    if (vec->length < vec->capacity / 4) {
        vec_shrink(vec); // Optionally shrink the vector
    }

    return element; // Returning the removed element (caller may decide to free it)
}

void vec_cleanup(vector* vec) {
    for (size_t i = 0; i < vec->length; i++) {
        free(vec->data[i]); // Free each element
    }
    free(vec->data); // Free the data array
    free(vec); // Free the vector itself
}

static bool vec_shrink(vector* vec) {
    if (vec->capacity <= 10) return true; // Minimum capacity reached, do not shrink further
    size_t newCapacity = vec->capacity / 2;
    void** newData = realloc(vec->data, newCapacity * sizeof(void*));
    if (newData == NULL) {
        return false; // Reallocation failed
    }
    vec->data = newData;
    vec->capacity = newCapacity;
    return true;
}

