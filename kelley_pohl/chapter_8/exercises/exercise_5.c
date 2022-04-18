
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y, z) (x >= y) ? ((x >= z) ? x : z) : ((y >= z) ? y : z)

int main(void)
{
  int x, y, z, max;
  x = 10;
  y = 9;
  z = 12;

  max = MAX(x, y, z);
  printf("max of x, y, z is: %i\n", max);

  return EXIT_SUCCESS;
}
