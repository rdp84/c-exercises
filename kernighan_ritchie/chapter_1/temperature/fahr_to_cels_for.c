#include <stdio.h>
#include <stdlib.h>

#define  LOWER  0
#define  UPPER  300
#define  STEP   20

int main(void)
{
  int fahr;

  printf("%s %s\n", "Fahrenheit", "Celsius");
  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    printf("   %3d     %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));

  return EXIT_SUCCESS;
}
