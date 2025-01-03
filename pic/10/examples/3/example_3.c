#include <stdio.h>

/* Use of uninitialized variable before accessing it */
int main(void) {
  int i;
  while (i < 10) {
    printf("%d\n", i);
    i++;
  }
  return 0;
}
