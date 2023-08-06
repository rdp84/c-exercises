#include "vector_matrix.h"

int
main(void)
{
  int i, j;
  vector a,
    b = {1.0, 2.0, 3.0},
    c = {4.0, 5.0, 6.0};

  matrix x,
    y = {
      {1.0, 2.0, 3.0},
      {4.0, 5.0, 6.0},
      {7.0, 8.0, 9.0}
    },
    z = {
      {1.0, 2.0, 3.0},
      {4.0, 5.0, 6.0},
      {7.0, 8.0, 9.0}
    };

  add(a, b, c);
  printf("addition of b + c, leaves us with:\n( ");
  for (i = 0; i < N; i++)
    printf("%f%s", a[i], i == N-1 ? " )\n" : ", ");

  multiply(x, y, z);
  printf("multiplication of y * z, leaves us with:\n{\n");
  for (i = 0; i < N; i++) {
    printf("\t( ");
    for (j = 0; j < N; j++)
      printf("%.1f%s", x[i][j], j == N-1 ? " )\n" : ", ");
  }
  printf("}\n");

  return EXIT_SUCCESS;
}
