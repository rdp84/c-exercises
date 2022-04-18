
#include <stdio.h>
#include <stdlib.h>

// Problem with #define PRN(x) printf("x\n"); is that the macro parameter
// x is not actually passed into the printf statement and rather the character x
// is printed out.

// Fix for this. # causes argument to be surrounded by double quotes -
// stringization
#define PRN(x) printf(#x "\n")

int main(void)
{
  PRN(Hello from main());
  return EXIT_SUCCESS;
}
