#include "munit.h"
#include "vector.h"
#include <stdio.h>

typedef struct student_t {
	char* name;
	int g_number;
	float gpa;
} Student;

static MunitResult test_char_compatibility(const MunitParameter params[], void* data ){
	vector* v = NEW_VECTOR(char, 100);
	munit_assert_not_null( v );
	munit_assert_true(v->type_size == sizeof(char));
	munit_assert_true(v->capacity == 100);
	for(int i=65; i<115; ++i){
		char c = (char)i;
		vec_add(v, &c);
		munit_assert_true( VECTOR_GET(char, v, i-65) == (char)i );
	}
	munit_assert_true(v->length == 50 && v->capacity == 100);
	vec_cleanup( v );
	return MUNIT_OK;
}

static MunitResult test_int_compatibility(const MunitParameter params[], void* data ){
	vector* v = NEW_VECTOR(int, 100);
	munit_assert_not_null( v );
	munit_assert_true(v->type_size == sizeof(int));
	munit_assert_true(v->capacity == 100);
	for(int i=0; i<50; ++i){
		int c = (int)i;
		vec_add(v, &c);
		munit_assert_true( VECTOR_GET(int, v, i) == (int)i );
	}
	munit_assert_true(v->length == 50 && v->capacity == 100);
	vec_cleanup( v );
	return MUNIT_OK;
}

static MunitResult test_student_struct_compatibility(const MunitParameter params[], void* data ){
	vector* v = NEW_VECTOR(Student, 100);
	munit_assert_not_null( v );
	munit_assert_true(v->type_size == sizeof(Student));
	munit_assert_true(v->capacity == 100);
	for(int i=0; i<50; ++i){
		Student c;
		c.g_number = i;
		c.name = "Good student";
		c.gpa = 4.0;
		vec_add(v, &c);
		Student tmp = VECTOR_GET(Student, v, i);
		munit_assert_true( tmp.g_number == i );
	}
	munit_assert_true(v->length == 50 && v->capacity == 100);
	vec_cleanup( v );
	return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
	{
		(char*)"Type tests - char",
		test_char_compatibility,
		NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL
	},
	{
		(char*)"Type tests - int",
		test_int_compatibility,
		NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL
	},
	{
		(char*)"Type tests - Student",
		test_student_struct_compatibility,
		NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL
	},

	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE }

};

static const MunitSuite test_suite = {
	(char*)"Vector tests",
	test_suite_tests,
	NULL,
	MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc+1)]){
	return munit_suite_main(&test_suite, (void*) "munit", argc, argv);
}
