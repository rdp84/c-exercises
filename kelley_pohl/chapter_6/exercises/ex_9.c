#include <stdio.h>

#define    N   4

int
main(void)
{
  // Array of size 4 but intialized with 5 elements
  int a[N] = {0, 2, 2, 3, 4};

  // Size of array is negative
  int b[N - 5];

  // Size of array is non-integer type
  int c[3.0];
}
