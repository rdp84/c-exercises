#include <stdio.h>

int main(void) {
  /* Stack allocate array */
  int x[10];
  /* Access uninitialized variable. This is undefined, compiler is free to do anything it likes */
  printf("%d\n", x[0]);
  return 0;
}
