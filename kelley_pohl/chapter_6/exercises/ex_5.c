#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  char a, b, c, *p, *q, *r;

  /*
   * Locations are in order but decreasing so a has the highest memory
   * address and r the lowest
   * Since a pointer stores an address in memory, then on x64 that requires
   * 8 bytes. This is aligned, i.e., they are positioned at 0xAB0 or 0xAB8
   * but not 0xAB2
   */

  printf("a: %p\n", &a);
  printf("b: %p\n", &b);
  printf("c: %p\n", &c);
  printf("p: %p\n", &p);
  printf("q: %p\n", &q);
  printf("r: %p\n", &r);
}
