#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float fahr, celsius;
  int   lower, upper, step;

  lower = 0;
  upper = 40;
  step = 2;

  printf("%s %s\n", "Celsius", "Fahrenheit");
  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;
    printf("  %2.0f     %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return EXIT_SUCCESS;
}
