#include <stdio.h>
#include <stdlib.h>

#define max(A, B)  ((A) > (B) ? (A) : (B))

int
main(void)
{
  int x, y, p, q;

  x = 10;
  y = 12;
  p = 3;
  q = 7;
  printf("max(10, 12): %d\n", max(x, y));
  printf("max(10 + 12, 3 + 7): %d\n", max(x + y, p + q));

  return EXIT_SUCCESS;
}
