#include "matrix.h"

int main(void) {
  double *a, *b, *c;

  a = create_matrix();
  print_matrix(a);

  b = create_matrix();
  print_matrix(b);

  c = add_transpose(a, b);
  print_matrix(c);
  free_matrix(c);

  c = add_transpose_blocked(a, b, 2);
  print_matrix(c);

  free_matrix(a);
  free_matrix(b);
  free_matrix(c);
  
  return 0;
}
