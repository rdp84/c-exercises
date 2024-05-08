#include <stdio.h>
#include <stdlib.h>

struct foo {
  int a;
  int b;
};

int main(void) {
  /* Accessing a null pointer is undefined */
  struct foo *x = NULL;
  /* So accessing fields of x is undefined */
  int m = x->a;
  /* Any possible behaviour is legal */
  printf("%d\n", m);
  return 0;
}
