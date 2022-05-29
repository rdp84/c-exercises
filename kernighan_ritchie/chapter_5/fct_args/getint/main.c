#include "getint.h"

int
main(void)
{
  int n, array[ARRAYSIZE];

  for (n = 0; n < ARRAYSIZE && getint(&array[n]) != EOF; n++)
    ;

  for(n = 0; n < ARRAYSIZE; n++)
    printf("array[%d]: %d\n", n, array[n]);

  return EXIT_SUCCESS;
}
