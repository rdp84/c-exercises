#include "structs.h"

#define N 1000

int main(void) {
  DataVec *d = iota_array(N);
  traverse(N, d);
  free_vec(d);
  return 0;
}
