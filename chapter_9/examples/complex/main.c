
#include "complex.h"

int main(void)
{
  complex a, b, c;

  b.re = 2;
  b.im = 4;

  c.re = 3;
  c.im = 5;

  add(&a, &b, &c);

  printf("a.re = %lf\n" \
         "a.im = %lf\n", a.re, a.im);
  print_complex(&a);

  return EXIT_SUCCESS;
}

void add(complex *a, complex *b, complex *c)
{
  a->re = b->re + c->re;
  a->im = b->im + c->im;
}

void print_complex(complex *a)
{
  printf("a->re = %lf\n" \
         "a->im = %lf\n", a->re, a->im);
}
