#include <stdio.h>

int
main(void)
{
  int x = 1, y = 2;
  int *pi;
  int **ppi;

  pi = &x;
  ppi = &pi;
  printf("%p, %p, %d=%d=%d\n", ppi, pi, x, *pi, **ppi);

  pi = &y;
  printf("%p, %p, %d=%d=%d\n", ppi, pi, y, *pi, **ppi);

  return 0;
}
