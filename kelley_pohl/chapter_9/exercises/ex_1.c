
#include <stdio.h>
#include <stdlib.h>

#define DOLLARS float
/* typedef float DOLLARS; */

int main(void)
{
  DOLLARS amount = 100.0, interest = 0.07 * amount;
  printf("DOLLARS = %.2f\n", amount + interest);

  return EXIT_SUCCESS;
}
