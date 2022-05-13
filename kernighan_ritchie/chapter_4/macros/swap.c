#include <stdio.h>
#include <stdlib.h>

#define swap(t, x, y) { t z; z = x; x = y; y = z; }

int
main(void)
{
  int  a, b;

  a = 3;
  b = 5;

  printf("a: %d\nb: %d\n", a, b);
  swap(int, a, b);
  printf("a: %d\nb: %d\n", a, b);
  
  return EXIT_SUCCESS;
}
