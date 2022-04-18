
#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
  double re; // real part
  double im; // imaginary part
} complex, *complexPtr;

#define REAL(a)              a->re
#define  IMG(a)              a->im
#define  ADD(a, b, c)             \
  a->re = REAL(b) + REAL(c);      \
  a->im =  IMG(b) +  IMG(c)
#define PRINT(a)                  \
  printf("a->re = %lf\n"          \
         "a->im = %lf\n",         \
         a->re, a->im)
