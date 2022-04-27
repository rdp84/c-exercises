#include <stdio.h>
#include <stdlib.h>

int bitcount_naive(unsigned x);
int bitcount_fast(unsigned x);

int
main(void)
{
  printf("%d\n", bitcount_naive(3));
  printf("%d\n", bitcount_fast(3));
  return EXIT_SUCCESS;
}

/* bitcount_naive: count 1 bits in x by repeatedly rightshifting */
int
bitcount_naive(unsigned x)
{
  int b;

  for (b = 0; x > 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

/* bitcount_fast: count 1 bits in x by deleting rightmost 1 bit */
int
bitcount_fast(unsigned x)
{
  int b;

  for (b = 0; x > 0; x &= (x - 1))
    b++;

  return b;
}
