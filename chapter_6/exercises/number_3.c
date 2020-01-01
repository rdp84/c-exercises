
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a, b, *p = &a, *q = &b;
  ptrdiff_t diff = p - q;
  printf("%s%li\n", "diff = ", diff);

  diff = p - (int *) 0;
  printf("%s%li\n", "diff = ", diff);
  
  return EXIT_SUCCESS;
}
