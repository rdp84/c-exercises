#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);
int      wordlength(void);

int
main(void)
{
  printf("%u\n", rightrot(3, 2)); /* 2^30 + 2^29 */
  return EXIT_SUCCESS;
}

/* rightrot: returns the value of x rotated to the right by n bit positions */
unsigned
rightrot(unsigned x, int n)
{
  unsigned mask;

  /* nothing changes if n is the same as word length, else it is the remainder */
  if ((n = n % wordlength()) > 0) {
    mask = ~(~0 << n);           /* mask with ones in rightmost n-bits */
    mask &= x;                   /* set rightmost n-bits to what x holds */
    mask <<= (wordlength() - n); /* shift these to the leftmost position */
    x >>= n;                     /* rightshift x by n-bits */
    x |= mask;                   /* turn on bits */
  }

  return x;
}

/* wordlength: computes word length of the machine */
int
wordlength(void)
{
  int i;
  unsigned v = (unsigned) ~0;

  for (i = 0; (v = v >> 1) > 0; ++i)
    ;
  return i;
}
