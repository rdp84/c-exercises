#include <stdio.h>

int main(void) {
  /* Divide by zero is undefined */
  int n = 65;
  /* So value of m is undefined */
  int m = n / (n - n);
  /* Any possible behaviour is legal */
  printf("%d\n", m);

  return 0;
}
