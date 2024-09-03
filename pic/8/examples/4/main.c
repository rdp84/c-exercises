#include "structs.h"

#define N 1000

int main(void) {
  DataVec *d = iota_array(N);
  traverse(N, d);
  return 0;
}
