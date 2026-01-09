#include <stdio.h>
#include <string.h>
#include "vectors.h"

void print_int(const void* element) {
  printf("%d ", *(const int*)element);
}

void print_double(const void* element) {
  printf("%.2f ", *(const double*)element);
}

void print_string(const void* element) {
  printf("\"%s\" ", (const char*)element);
}

int main(void) {
  printf("--- Vector Demo ---\n\n");

  // Integer vector demo
  printf("1.Integer Vector:\n");
  Vector* int_vec = init_vector(sizeof(int), 5);
  
  printf("Adding numbers 1-10: ");
  for (int i = 1; i <= 10; i++) {
    push_back(int_vec, &i);
  }
  print_vector(int_vec, print_int);
  
  printf("   Size: %zu\n", get_size(int_vec));
  
  int element;
  get_element_at(int_vec, 3, &element);
  printf("Element at index 3: %d\n", element);
  
  printf("After pop_back: ");
  pop_back(int_vec, &element);
  printf("(removed %d) ", element);
  print_vector(int_vec, print_int);
  
  printf("After reverse: ");
  reverse_vector(int_vec);
  print_vector(int_vec, print_int);
  
  free_vector(int_vec);
  printf("\n");

  // Double vector demo
  printf("2.Double Vector:\n");
  Vector* double_vec = init_vector(sizeof(double), 3);
  
  printf("Adding doubles: ");
  double d1 = 3.14, d2 = 2.71, d3 = 1.41;
  push_back(double_vec, &d1);
  push_back(double_vec, &d2);
  push_back(double_vec, &d3);
  print_vector(double_vec, print_double);
  
  printf("Size: %zu\n", get_size(double_vec));
  free_vector(double_vec);
  printf("\n");

  // String vector demo
  printf("3.String Vector:\n");
  Vector* str_vec = init_vector(sizeof(char[20]), 2);
  
  printf("   Adding strings: ");
  char s1[20] = "Hello", s2[20] = "World", s3[20] = "C";
  push_back(str_vec, s1);
  push_back(str_vec, s2);
  push_back(str_vec, s3);
  print_vector(str_vec, print_string);
  
  printf("Size: %zu\n", get_size(str_vec));
  free_vector(str_vec);

  printf("\n--- Demo Complete ---\n");
  return 0;
}
