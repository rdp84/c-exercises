
#include <stdlib.h>
#include <stdio.h>


int main(void)
{

  unsigned int int_val = -1;
  unsigned long long_val = -1;

  // This shows the size difference between integer and longs.
  // On a 64-bit sysytem a long in likely to be 2 ^ 64.
  // On a 32-bit system an unsigned in is likely to be 2 ^ 32.
  
  printf("The largest unsigned integer value: %u\n", int_val);
  printf("The largest unsigned long value: %lu\n", long_val);
}
