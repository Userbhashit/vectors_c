#include <stdio.h>
#include "vectors.h"

int main (void) {

  Vector* int_vec = init_vector(INT, 5);
  
  for (int i = 0; i < 5; i++) {
    push_back(int_vec, i);
  }
  print_vector(int_vec);

  push_back(int_vec, 5);
  print_vector(int_vec);

  int ele;
  if (get_element_at(int_vec, 3, &ele) == 0) {
    printf("%d\n", ele);
  }

  printf("%zu\n", get_size(int_vec));

  free_vector(int_vec);

  return 0;
}
