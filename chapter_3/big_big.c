
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  int big_big = 2000000000 + 2000000000;

  // The total of tha addition is > 2 ^ 32 - 1 and therefore we wrap round to a negative number.
  printf("%d   %u\n", big_big, big_big);

  return EXIT_SUCCESS;
}
