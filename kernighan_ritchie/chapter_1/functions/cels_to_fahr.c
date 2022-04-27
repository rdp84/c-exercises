#include <stdio.h>
#include <stdlib.h>

float cels_to_fahr(float cels);

int
main(void)
{
  float celsius;
  int   lower, upper, step;

  lower = 0;
  upper = 40;
  step = 2;

  printf("%s %s\n", "Celsius", "Fahrenheit");
  celsius = lower;
  while (celsius <= upper) {
    printf("  %2.0f     %6.1f\n", celsius, cels_to_fahr(celsius));
    celsius = celsius + step;
  }

  return EXIT_SUCCESS;
}

float
cels_to_fahr(float cels)
{
  return ((9.0 / 5.0) * cels) + 32;
}
