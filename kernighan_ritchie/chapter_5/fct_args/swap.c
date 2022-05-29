#include <stdio.h>
#include <stdlib.h>

#define prn(x, y) printf(#x ": %d, " #y ": %d\n", x, y)

void swap(int *, int *);

int
main(void)
{
  int x, y;

  x = 4;
  y = 5;
  prn(x, y);

  swap(&x, &y);
  prn(x, y);

  return EXIT_SUCCESS;
}

/* swap: interchange *x and *y */
void
swap(int *x, int *y)
{
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}
