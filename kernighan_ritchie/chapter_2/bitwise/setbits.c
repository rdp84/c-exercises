#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int
main(void)
{
  printf("%d\n", setbits(46, 5, 3, 201)); /* 14 */
  return EXIT_SUCCESS;
}

/* 
   setbits: returns x with the n bits that begin at p set to the
   rightmost n bits of y
*/
unsigned
setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned mask;

  mask = ~(~0 << n);           /* mask with ones in rightmost n-bits */

  x &= ~(mask << (p + 1 - n)); /* zero out n bits starting at p */

  y &= mask;                   /* zero out all but rightmost n-bits */
  y <<= (p + 1 - n);           /* shift bits to p */

  return x | y;                /* turn on bits */
}
