#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "vectors.h"

static void print_int_vector(const Vector* vector);
static void print_float_vector(const Vector* vector);
static void print_long_vector(const Vector* vector);

//-------------------------------Maps to enum member-------------------------------
static size_t type_size[3] = {sizeof(int), sizeof(float), sizeof(long)};

Vector* init_vector(enum DataTypes data_type, size_t initial_capacity) {

  if (data_type < 0 || data_type > 3) {
    fprintf(stderr, "Please use correct data type.\n");
    return NULL;
  }

  if (initial_capacity == 0) {
    printf("Can't allocate with 0 elements, initial capacity of vector set to 1.\n");
    initial_capacity = 1;
  }

  Vector* vector = malloc(sizeof(Vector));
  if (!vector) {
    fprintf(stderr, "ALlocation of vector failed.\n");
    return NULL;
  }

  vector->data = malloc(initial_capacity * type_size[data_type]);
  if (!vector->data) {
    free(vector);
    fprintf(stderr, "Allocation of vector data array failed.\n");
    return NULL;
  }

  vector->size = 0;
  vector->data_type = data_type;
  vector->capacity = initial_capacity;

  return vector;
}

/* 
 * Push back will be a Variadic function so we can take any type of data
 * It is user's responsibilty to make sure correct data type is provided
 * If multiple element are passed only first one will be used
 */
void push_back(Vector* vector, ...) {

  if (!vector) {
    fprintf(stderr, "Vector was not initialized correctly, please initialize vector using init_vector().\n");
    return;
  }

  // Reasize the vector if full
  if (vector->size == vector->capacity) {
    size_t new_capacity = vector->capacity * 2;

    void* new_data_array = realloc(vector->data, new_capacity * type_size[vector->data_type]);
    if (!new_data_array) {
      fprintf(stderr, "Vector capacity full unable to allocate more memory.\nVector with old elements is safe.\n");
      return; 
    }

    vector->data = new_data_array;
    vector->capacity = new_capacity;
    printf("resized.\n");
  }

  va_list elements;
  va_start(elements, vector);

  switch (vector->data_type) {
    case INT: {
      int element = va_arg(elements, int);
      ((int*)vector->data)[vector->size++] = element;
      /* Equivalent to
       * int* ptr = vector->data;
       * ptr[vector->size++] = element;
      */ 
      break;
    }
    case FLOAT: {
      float element = (float)va_arg(elements, double);
      ((float*)vector->data)[vector->size++] = element;
      break;
    }
    case LONG: {
      long element = va_arg(elements, long);
      ((long*)vector->data)[vector->size++] = element;
      break;
    }
    default:
      printf("What!!!");
  }

  va_end(elements);
}

void print_vector(const Vector* vector) {
  if (!vector || !vector->data) {
    fprintf(stderr, "Vector was not initialized correctly, please initialize vector using init_vector().\n");
    return;
  } else if (vector->size == 0) {
    printf("Vector's empty.\n");
    return;
  } else {
    switch(vector->data_type) {
      case INT: 
        print_int_vector(vector);
        break;
      case FLOAT:
        print_float_vector(vector);
        break;
      case LONG:
        print_long_vector(vector);
        break;
    default:
      printf("What!!!");
    }
  }
}

// We take a generic pointer so we can put any type of element at given index
int get_element_at(const Vector* vector, size_t index, void* element_ptr) {
  if (!vector) {
    fprintf(stderr, "Vector not initialize.\n");
    return 1;
  } else if (vector->size == 0) {
    fprintf(stderr, "Vector is empty.\n");
    return 1;
  } else if (index >= vector->size) {
    fprintf(stderr, "Out of bounds.\n");
    return 1;
  }
  
  switch (vector->data_type) {
    case INT: {
      int* ptr = (int*) element_ptr;
      *ptr = ((int*)vector->data)[index];
      break;
    }
    case FLOAT: {
      float* ptr = (float*) element_ptr;
      *ptr = ((float*)vector->data)[index];
      break;
    }
    case LONG: {
      long* ptr = (long*) element_ptr;
      *ptr = ((long*)vector->data)[index];
      break;
    }
    default:
      printf("Wait.\n");
      break;
  }

  return 0;
}

size_t get_size(const Vector* vector) {
  return vector->size;
}

void free_vector(Vector* vector) {
  if (vector->data) free(vector->data);
  if (vector) free(vector);
}

// -------------Helper function---------------------
static void print_int_vector(const Vector* vector) {
  for (size_t i = 0; i < vector->size; i++) {
    printf("%d ", ((int*)vector->data)[i]); 
  }
  putchar('\n');
}

static void print_float_vector(const Vector* vector) {
  for (size_t i = 0; i < vector->size; i++) {
    printf("%f ", ((float*)vector->data)[i]); 
  }
  putchar('\n');
}

static void print_long_vector(const Vector* vector) {
  for (size_t i = 0; i < vector->size; i++) {
    printf("%ld ", ((long*)vector->data)[i]); 
  }
  putchar('\n');
}
