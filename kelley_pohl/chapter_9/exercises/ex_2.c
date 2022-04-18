
#include <stdio.h>
#include <stdlib.h>

/*
   If we replace typedef with below macro then this
   causes a compilation error at line:

   float DOLLARS;

   when the pre-processor expands this you get:

   float float;

   which is a declaration that cotains two or more types
*/

/*
#define DOLLARS float
*/

/* Associate identifier DOLLARS with type float */
typedef float DOLLARS;

int main(void)
{
  /*
     Variables amount, interest of type DOLLARS which
     is synonymous with float
  */
  DOLLARS amount = 100.00, interest = 0.07 * amount;

  {
    float DOLLARS; /* variable DOLLARS, type float */
    DOLLARS = amount + interest;
    printf("DOLLARS = %.2f\n", DOLLARS);
  }

  return EXIT_SUCCESS;
}
