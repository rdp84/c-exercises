#include <stdio.h>
#include <limits.h>

int main(void) {
  /* Signed integer overflow is undefined */
  int n = INT_MAX;
  /* So value of m is undefined */
  int m = n + 1;
  printf("%d\n", m);
  return 0;
}
