# Generic Vector in C

A simple generic vector implementation in C for learning purposes.

**Note:** This is a learning project. No AI was used in the development of this code.

## Features

* Generic vector implementation supporting any data type
* Dynamic resizing with automatic capacity management
* Basic vector operations: push, pop, access, reverse
* Memory-safe operations with proper error handling

## Functions

* `init_vector()` - Create a new vector
* `push_back()` - Add element to the end
* `pop_back()` - Remove element from the end
* `get_element_at()` - Access element at index
* `print_vector()` - Print vector contents
* `reverse_vector()` - Reverse vector order
* `get_size()` - Get current size
* `free_vector()` - Free vector memory

## Building

```bash
gcc -o main main.c vectors.c
gcc -o test test.c vectors.c

## Usage

Run the main example:
```bash
./main
```

Run tests:
```bash
./test
```
