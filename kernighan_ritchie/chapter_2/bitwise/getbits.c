#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n);

int
main(void)
{
  printf("%d\n", getbits(12, 4, 3));
  printf("%d\n", getbits(22, 5, 2));
  return EXIT_SUCCESS;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
