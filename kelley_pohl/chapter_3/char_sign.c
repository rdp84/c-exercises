
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  char c = -1;
  signed char s = -1;
  unsigned char u = -1;

  // SHow whether an ordinary char is signed or unsigned.
  // Can force the compiler to use unsigned say by passing option
  // -funsigned-char
  printf("c = %d   s = %d   u = %d\n", c, s, u);
  
  return EXIT_SUCCESS;
}
