#include "structs.h"

#define N 1000

int main(void) {
  Data *vector = iota_array(N);
  print_vector(N, vector);
  traverse(N, vector);
  print_vector(N, vector);
  return 0;
}
