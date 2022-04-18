
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{

  double x = -2.357;

  // This will print something undesirable because e expects a double but abs returns an int
  // We should therefore do an explicit cast to get the desired result.
  printf(" abs(x) = %e\n", abs(x));
  printf("fabs(x) = %e\n", fabs(x));

  return EXIT_SUCCESS;
}
