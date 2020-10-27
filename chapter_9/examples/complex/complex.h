
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double re; // real part
  double im; // imaginary part
} complex;

void add(complex *, complex *, complex *);
void print_complex(complex *);
