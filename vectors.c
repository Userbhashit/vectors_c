/*
 * vectors.c
 *
 * Simple dynamic array (vector) implementation for integers.
 * Automatically grows capacity when needed.
 */

#include <stdlib.h>
#include "vectors.h"

/*
 * Initializes a new intVector with the given initial capacity.
 *
 * If capacity is 0, it defaults to 1.
 *
 * Returns:
 *  - Pointer to a newly allocated intVector on success
 *  - NULL on allocation failure
 */
intVector* init_int_vector(size_t capacity) {
  
  if (capacity == 0) capacity = 1;

  intVector* new_vec = malloc(sizeof(intVector));

  if (!new_vec) return NULL;

  new_vec->vec = (int *)malloc(capacity * sizeof(int));

  if (!new_vec) {
    free(new_vec);
    return NULL;
  }

  new_vec->size = 0;
  new_vec->capacity = capacity;

  return new_vec;
}

/*
 * Appends a value to the end of the vector.
 *
 * Automatically resizes the internal buffer if capacity is reached.
 *
 * Note:
 *  - This function assumes the vector was initialized by init_int_vector.
 */
void int_vector_push_back(intVector* vector, int val) {

  if (!vector) {
    fprintf(stderr, "vector not properly initialized.\n");
    return;
  }

  if (vector->size == vector->capacity) {
    size_t new_cap = vector->capacity * 2;
    int *tmp = realloc(vector->vec, new_cap * sizeof(int));

    if (!tmp) {
      fprintf(stderr, "Error: vector growth failed, can't add new element.\n");
      return;
    }

    // Grow capacity if needed
    vector->vec = tmp;
    vector->capacity = new_cap;
  }

  vector->vec[vector->size++] = val;
}

/*
 * Retrieves the element at the given index.
 *
 * Returns:
 *  - 0 on success, and writes the value to `element`
 *  - non-zero if index is out of bounds or arguments are invalid
 */
int get_int_at(const intVector* vector, size_t index, int* element) {
  if (!vector || !element || index >= vector->size) {
    return 1;
  }

  *element = vector->vec[index];
  return 0;
}

size_t get_size(const intVector* vector) {
  return vector ? vector->size : 0;
}

void print_int_vector(const intVector* vector) {
  if (!vector) return;

  for (size_t index = 0; index < vector->size; index++) {
    printf("%d ", vector->vec[index]);
  }
  putchar('\n');
}

void free_int_vector(intVector* vector) {

  if (!vector) return;

  free(vector->vec);
  free(vector);
}
