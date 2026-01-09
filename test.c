#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "vectors.h"

void print_int(const void* element) {
  printf("%d ", *(const int*)element);
}

void test_init_vector() {
  printf("Testing init_vector... ");
  Vector* vec = init_vector(sizeof(int), 5);
  assert(vec != NULL);
  assert(vec->size == 0);
  assert(vec->capacity == 5);
  assert(vec->element_size == sizeof(int));
  free_vector(vec);
  printf("PASS\n");
}

void test_push_back() {
  printf("Testing push_back... ");
  Vector* vec = init_vector(sizeof(int), 2);
  
  int val1 = 10, val2 = 20, val3 = 30;
  push_back(vec, &val1);
  assert(vec->size == 1);
  
  push_back(vec, &val2);
  assert(vec->size == 2);
  
  push_back(vec, &val3);
  assert(vec->size == 3);
  assert(vec->capacity >= 3);
  
  free_vector(vec);
  printf("PASS\n");
}

void test_get_element_at() {
  printf("Testing get_element_at... ");
  Vector* vec = init_vector(sizeof(int), 3);
  
  int vals[] = {100, 200, 300};
  for (int i = 0; i < 3; i++) {
    push_back(vec, &vals[i]);
  }
  
  int result;
  get_element_at(vec, 0, &result);
  assert(result == 100);
  
  get_element_at(vec, 2, &result);
  assert(result == 300);
  
  free_vector(vec);
  printf("PASS\n");
}

void test_pop_back() {
  printf("Testing pop_back... ");
  Vector* vec = init_vector(sizeof(int), 3);
  
  int vals[] = {1, 2, 3};
  for (int i = 0; i < 3; i++) {
    push_back(vec, &vals[i]);
  }
  
  int removed;
  pop_back(vec, &removed);
  assert(removed == 3);
  assert(vec->size == 2);
  
  free_vector(vec);
  printf("PASS\n");
}

void test_reverse_vector() {
  printf("Testing reverse_vector... ");
  Vector* vec = init_vector(sizeof(int), 4);
  
  int vals[] = {1, 2, 3, 4};
  for (int i = 0; i < 4; i++) {
    push_back(vec, &vals[i]);
  }
  
  reverse_vector(vec);
  
  int result;
  get_element_at(vec, 0, &result);
  assert(result == 4);
  get_element_at(vec, 3, &result);
  assert(result == 1);
  
  free_vector(vec);
  printf("PASS\n");
}

void test_get_size() {
  printf("Testing get_size... ");
  Vector* vec = init_vector(sizeof(int), 5);
  
  assert(get_size(vec) == 0);
  
  int val = 42;
  push_back(vec, &val);
  assert(get_size(vec) == 1);
  
  pop_back(vec, NULL);
  assert(get_size(vec) == 0);
  
  free_vector(vec);
  printf("PASS\n");
}

void test_edge_cases() {
  printf("Testing edge cases... ");
  
  Vector* vec = init_vector(sizeof(int), 1);
  int val = 5;
  
  push_back(vec, &val);
  push_back(vec, &val);
  push_back(vec, &val);
  
  assert(vec->size == 3);
  assert(vec->capacity >= 3);
  
  int result;
  assert(get_element_at(vec, 10, &result) != 0);
  
  pop_back(vec, NULL);
  pop_back(vec, NULL);
  pop_back(vec, NULL);
  pop_back(vec, NULL);
  
  free_vector(vec);
  printf("PASS\n");
}

int main(void) {
  printf("=== Running Vector Tests ===\n\n");
  
  test_init_vector();
  test_push_back();
  test_get_element_at();
  test_pop_back();
  test_reverse_vector();
  test_get_size();
  test_edge_cases();
  
  printf("\n=== All Tests Passed! ===\n");
  return 0;
}
