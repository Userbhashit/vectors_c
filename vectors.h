#ifndef VECTORS_H
#define VECTORS_H

#include <stdio.h>

// All the supported data types
// To allocate proper amount of memory 
// we map enum member to type_size array (declared in vectors.c)
enum DataTypes {
  INT,
  FLOAT,
  LONG
};

typedef struct Vector {
  enum DataTypes data_type;
  void* data;
  size_t size;
  size_t capacity;
} Vector;

Vector* init_vector(enum DataTypes data_type, size_t initial_capacity);
void push_back(Vector* vector, ...);
void print_vector(const Vector* vector);
int get_element_at(const Vector* vector, size_t index, void* element);
size_t get_size(const Vector* vector);
void free_vector(Vector* vector);

// Add int_vector_pop_back
// Add int_vector_reserve
// Add int_vector_shrink_to_fit
// Add errno-style error codes

#endif
