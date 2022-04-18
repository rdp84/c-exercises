
#include "complex.h"

int main(void)
{
  complexPtr a, b, c;

  a = malloc(sizeof(complex));
  b = malloc(sizeof(complex));
  c = malloc(sizeof(complex));

  REAL(b) = 2;
   IMG(b) = 4;

  REAL(c) = 3;
   IMG(c) = 5;

  ADD(a, b, c);
  PRINT(b);
  PRINT(c);
  PRINT(a);

  free(a);
  free(b);
  free(c);

  return EXIT_SUCCESS;
}
