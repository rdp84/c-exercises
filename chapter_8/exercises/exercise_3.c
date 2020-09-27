
#include <stdio.h>
#include <stdlib.h>

// Don't want to use stringization here since this will conver to char *
// Can just use simple formatting
#define PRN3(x, y, z)    printf("x has value %.1f and " \
                                "y has value %.1f and " \
                                "z has value %.1f\n", x, y, z)

int main(void)
{
  float x, y, z;
  x = 1.1;
  y = 2.2;
  z = 3.3;

  PRN3(x, y, z);

  return EXIT_SUCCESS;
}
