# Resizable Vector Data Structure in C

## Overview

This repository contains an implementation of a resizable vector in C, designed to store elements of any data type. It supports automatic resizing for efficient memory usage and provides basic operations such as add, get, and remove.

## Features

- **Generic Type Support**: Capable of storing data of any type, facilitating usage across various data handling needs.
- **Dynamic Resizing**: Automatically increases or decreases its capacity based on the number of elements it holds, optimizing memory usage.
- **Memory Management**: Manages its own memory, ensuring efficient allocation and deallocation of resources.

## Functions Overview

- **Initialization**: Create a new vector with a specified initial capacity and data type size.
- **Addition**: Add an element to the vector.
- **Retrieval**: Retrieve an element at a specific index.
- **Removal**: Remove an element at a specific index and return it.
- **Cleanup**: Free all memory associated with the vector, including its elements.

## Building and Running

To use the vector, include its header file in your C project and ensure your compiler supports the C99 standard or later. Compile your project files with a suitable C compiler such as gcc.

## Testing

The vector comes with a suite of tests to verify functionality across different operations and data types. These tests ensure the vector's reliability for adding, retrieving, and removing elements, as well as managing memory correctly.

## Contributing

Contributions are welcome. If you'd like to improve the vector or suggest new features, feel free to fork this repository and submit a pull request.

## License

This project is released under the MIT License, which allows modification and distribution of the code for both private and commercial use. See the `LICENSE` file for more details.
