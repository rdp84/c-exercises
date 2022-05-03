#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int
main(void)
{
  printf("%d\n", invert(71, 5, 3)); /* 127 */
  return EXIT_SUCCESS;
}

/* invert: returns x with the n bits that begin at p inverted */
unsigned
invert(unsigned x, int p, int n)
{
  unsigned mask;

  mask = ~(~0 << n);   /* mask with ones in rightmost n bits */
  mask <<= (p + 1 -n); /* shift the ones to p */
  return x ^ mask;     /* exclusive or with ones inverts, zeros remain the same */  
}
