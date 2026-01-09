#ifndef VECTORS_H
#define VECTORS_H

#include <stdio.h>

typedef struct Vector {
  void* data;
  size_t size;
  size_t capacity;
  size_t element_size;
} Vector;

Vector* init_vector(size_t element_size, size_t initial_capacity);
void push_back(Vector* vector, const void* element);
void pop_back(Vector* vector, void* deleted_element);
void print_vector(const Vector* vector, void (*print_element)(const void*));
int get_element_at(const Vector* vector, size_t index, void* out_element);
size_t get_size(const Vector* vector);
void reverse_vector(Vector* vector);
void free_vector(Vector* vector);

// Add int_vector_shrink_to_fit

#endif
