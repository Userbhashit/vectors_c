#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vectors.h"

Vector* init_vector(size_t element_size, size_t initial_capacity) {

  if (initial_capacity == 0) initial_capacity = 1;

  Vector* new_vector = malloc(sizeof(Vector));
  if (!new_vector) {
    fprintf(stderr, "Allocation of vector failed.\n");
    return NULL;
  }
  
  new_vector->data = malloc(element_size * initial_capacity);
  if (!new_vector->data) {
    fprintf(stderr, "Allocation of array failed.\n");
    free(new_vector);
    return NULL;
  }

  new_vector->size = 0;
  new_vector->capacity = initial_capacity;
  new_vector->element_size = element_size;

  return new_vector;
}

void push_back(Vector* vector, const void* element) {
  if (!vector || !element) {
    fprintf(stderr, "vector or element can't be NULL.\n");
    return;
  }

  if (vector->size == vector->capacity) {
    size_t new_capacity = vector->capacity * 2;
    void* new_array = realloc(vector->data, vector->element_size * new_capacity);

    if (!new_array) {
      fprintf(stderr, "Reallocaction of new array with more memory failed.\nOld data is untouched.\n");
      return;
    }

    vector->data = new_array;
    vector->capacity = new_capacity;
  }

  // Calculate position for new element and copy it
  memcpy((char*)vector->data + vector->element_size * vector->size, element, vector->element_size);
  vector->size++;
}

void pop_back(Vector* vector, void* deleted_element) {
  if (!vector || !vector->data) {
    fprintf(stderr, "Invalid vector.\n");
    return;
  } 
  if (vector->size == 0) {
    printf("Vector is empty.\n");
    return;
  } 

  if (deleted_element) {
    // Copy last element to output buffer if provided
    size_t last_index = vector->size - 1;
    void* src = (char*) vector->data + last_index * vector->element_size;
    memcpy(deleted_element, src, vector->element_size);
  }
  vector->size--;
}

void print_vector(const Vector *vector, void (*print_element)(const void *)) {
  if (!vector) {
    fprintf(stderr, "Invalid vector pointer.\n");
    return;
  } else if (!print_element) {
    fprintf(stderr, "Invalid print function pointer.\n");
    return;
  } else if (vector->size == 0) {
    fprintf(stderr, "Empty vector.\n");
    return;
  } else {
    // Iterate through elements and call print function
    for (size_t i = 0; i < vector->size; i++) {
      const void* element_ptr = (const char*)vector->data + (i * vector->element_size);
      print_element(element_ptr);
    }
    putchar('\n');
  }
}

int get_element_at(const Vector *vector, size_t index, void* out_element) {
    if (!vector || !vector->data) {
        fprintf(stderr, "Invalid vector.\n");
        return 1;
    }

    if (index >= vector->size) {
        fprintf(stderr, "Out of bounds access.\n");
        return 1;
    }

    // Copy element at index to output buffer
    memcpy(out_element, (char *)vector->data + index * vector->element_size, vector->element_size);
    return 0;
}

size_t get_size(const Vector* vector) {

  if (!vector) {
    fprintf(stderr, "Invalid vector.\n");
    return 0;
  }

  return vector->size;
}

void reverse_vector(Vector* vector) {

  if (!vector) {
    fprintf(stderr, "Vector is NULL.\n");
    return;
  }

  size_t left = 0;
  size_t right = vector->size - 1;
  void* temp = malloc(vector->element_size);

  // Swap elements from both ends moving towards center
  while (left < right) {
    void* left_ptr = (char*)vector->data + left * vector->element_size;
    void* right_ptr = (char*)vector->data + right * vector->element_size;

    memcpy(temp, left_ptr, vector->element_size);
    memcpy(left_ptr, right_ptr, vector->element_size);
    memcpy(right_ptr, temp, vector->element_size);

    left++; right--;
  }

  free(temp);
}

void free_vector(Vector* vector) {
  if(!vector) return;

  if (vector->data) free(vector->data);
  free(vector);
}
