#ifndef VECTORS_H
#define VECTORS_H

#include <stdio.h>

typedef struct intVector {
  int* vec;
  size_t size;
  size_t capacity;
} intVector;

intVector* init_int_vector(size_t capacity);
void int_vector_push_back(intVector* vector, int val);
int get_int_at(const intVector* vector, size_t index, int* element);
void print_int_vector(const intVector* vector);
size_t get_size(const intVector* vector);
void free_int_vector(intVector* vector);

// Add int_vector_pop_back
// Add int_vector_reserve
// Add int_vector_shrink_to_fit
// Add errno-style error codes

#endif
