
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);

int main(void)
{

  double x;

  for (x = -0.25; x <= 0.25; x += 0.01)
    printf("f(%+.2f) = %+.15f\n", x, f(x));
  return EXIT_SUCCESS;
}

double f(double x)
{
  return (tan(sin (x)) - sin(tan (x)));
}
