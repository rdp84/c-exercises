#include <stdlib.h>
#include <stdio.h>

#define N 10

int main(void) {
  int i;
  char s[N] = "123456789";

  /* Loop bound, goes past the end of the array. Undefined behaviour */
  for (i = 0; i <= N; i++)
    printf("%c", s[i]);
  printf("\n");

  return 0;
}
