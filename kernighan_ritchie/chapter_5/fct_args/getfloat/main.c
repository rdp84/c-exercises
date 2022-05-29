#include "getfloat.h"

int
main(void)
{
  int     n;
  double  array[ARRAYSIZE];

  for (n = 0; n < ARRAYSIZE && getfloat(&array[n]) != EOF; n++)
    ;

  for(n = 0; n < ARRAYSIZE; n++)
    printf("array[%d]: %g\n", n, array[n]);

  return EXIT_SUCCESS;
}
