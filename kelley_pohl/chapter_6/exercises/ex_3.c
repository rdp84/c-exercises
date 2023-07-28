#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int
main(void)
{
  int       a, b, *p = &a, *q = &b;
  ptrdiff_t diff = p - q;

  printf("diff = %ld\n", diff);

  diff = p - (int *) 0;
  printf("diff = %ld\n", diff);
  
  return EXIT_SUCCESS;
}
