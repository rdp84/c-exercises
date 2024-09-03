#include <stdlib.h>
#include <stdio.h>
#include "complex.h"

Complex cons_complex(double re, double im) {
  Complex complex;
  complex.re = re;
  complex.im = im;

  return complex;
}

ComplexList_t cons_complex_list(Complex complex) {
  ComplexList_t retValue = malloc(sizeof(ComplexList));
  retValue->data = complex;
  retValue->tail = NULL;

  return retValue;
}

void print_complex_list(ComplexList_t list) {
  if (list == NULL) {
    return;
  } else {
    printf("re: %f, im: %f\n", list->data.re, list->data.im);
    print_complex_list(list->tail);
  }
}

void free_complex(ComplexList_t list) {
  if (list == NULL) {
    return;
  } else {
    free_complex(list->tail);
    free(list);
  }
}
