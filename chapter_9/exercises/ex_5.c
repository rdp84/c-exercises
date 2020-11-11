
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N  21

typedef struct {
  double re;
  double im;
} complex;

complex mult(complex, complex);
void    mult_ptr(complex *, complex *, complex *);

int main(void)
{
  complex c,
    numbers[N] = {{1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0},
                  {1.0, 4.0}, {1.0, 5.0}, {1.0, 6.0},
                  {1.0, 7.0}, {1.0, 8.0}, {1.0, 9.0},
                  {1.0, 10.0}, {1.0, 11.0}, {1.0, 12.0},
                  {1.0, 13.0}, {1.0, 14.0}, {1.0, 15.0},
                  {1.0, 16.0}, {1.0, 17.0}, {1.0, 18.0},
                  {1.0, 19.0}, {1.0, 20.0}, {1.0, 21.0}};

  int i;
  printf("Clock ticks for mult_ptr: %ld\n", clock());
  for (i = 1; i < N; ++i) {

    printf("(%.2lf + %.2lfi) * (%.2lf + %.2lfi)\n",
           numbers[i - 1].re, numbers[i - 1].im,
           numbers[i].re, numbers[i].im);
    // c = mult(numbers[i - 1], numbers[i]);
    mult_ptr(&c, &numbers[i - 1], &numbers[i]);
    printf("c = %lf + %lfi\n", c.re, c.im);
  }
  printf("Clock ticks for mult_ptr: %ld\n", clock());

  return EXIT_SUCCESS;
}

complex mult(complex b, complex c)
{
  complex a;

  a.re = (b.re * c.re) - (b.im * c.im);
  a.im = (b.im * c.re) + (b.re * c.im);

  return a;
}

void mult_ptr(complex *a, complex *b, complex *c)
{
  a -> re = (b -> re * c -> re) - (b -> im * c -> im);
  a -> im = (b -> im * c -> re) + (b -> re * c -> im);
}
