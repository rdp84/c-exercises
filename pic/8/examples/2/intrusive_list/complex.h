#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex {
  double re;
  double im;
};
typedef struct Complex Complex;

struct ComplexList {
  Complex data;
  struct ComplexList *tail;
};
typedef struct ComplexList ComplexList;
typedef ComplexList* ComplexList_t;

Complex cons_complex(double, double);
ComplexList_t cons_complex_list(Complex);
void print_complex_list(ComplexList_t);
void free_complex(ComplexList_t);

#endif
