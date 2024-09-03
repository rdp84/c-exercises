#include <stdlib.h>
#include "structs.h"

#define N 1000

int main(void) {
  Data *vector = iota_array(N);
  print_vector(N, vector);
  traverse(N, vector);
  print_vector(N, vector);
  free(vector);
  return 0;
}
