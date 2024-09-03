#include <stdlib.h>
#include "structs.h"

Complex_t complex_cons(double re, double im) {
  Complex_t retValue = (Complex_t) malloc(sizeof(Complex));
  retValue->re = re;
  retValue->im = im;
  return retValue;
}

Coord_t coord_cons(int x, int y) {
  Coord_t retValue = (Coord_t) malloc(sizeof(Coord));
  retValue->x = x;
  retValue->y = y;
  return retValue;
}
