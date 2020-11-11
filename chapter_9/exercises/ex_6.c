
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

/* Create an abbreviation */
typedef double dbl;

/*
  Create a type named trig_ptr to hold a pointer to a
  function that takes a double and returns a double

typedef dbl (*trig_ptr)(dbl);
*/

/*
  Create a type named trig that is a function that takes
  a double and returns a double
*/
typedef dbl trig(dbl);

/*
  Creates a type named trig_ptr to hold a pointer to
  type trig. Type trig is a function that takes a double
  and returns a double
 */
typedef trig *trig_ptr;

int main(void)
{
  /*
    Headers for two trigonometric functions:
    double sin(double);
    double cos(double);
  */

  trig_ptr f = &sin, g = &cos;

  /*
    Above could also be written as:

    trig *f = &sin, *g = &cos;

    if we wished to not use the trig_ptr type
  */

  printf("f(%f) = %f\n", PI, f(PI));
  printf("g(%f) = %f\n", PI, g(PI));

  return EXIT_SUCCESS;
}
