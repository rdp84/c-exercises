#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int
main(void)
{
  int       a, b, *p = &a, *q = &b;
  ptrdiff_t diff = p - q;

  /*
   * This prints the number of integer elements between p & q
   * Since they are allocated one after the other then it will
   * print 1.
   */
  printf("diff = %ld\n", diff);

  /*
   * (int *) 0 gives address zero so p - 0 is the number of ints
   * between 0 & p. An int is 4 bytes so it is ((p byte address) / 4)
   */
  diff = p - (int *) 0;
  printf("diff = %ld\n", diff);
  
  return EXIT_SUCCESS;
}
