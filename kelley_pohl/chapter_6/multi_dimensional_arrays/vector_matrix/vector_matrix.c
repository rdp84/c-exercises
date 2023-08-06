#include "vector_matrix.h"

void
add(vector x, vector y, vector z)
{
  int i;

  for (i = 0; i < N; i++)
    x[i] = y[i] + z[i];
}

scalar
dot_product(vector x, vector y)
{
  int    i;
  scalar sum = 0.0;

  for (i = 0; i < N; i++)
    sum += x[i] * y[i];

  return sum;
}

void
multiply(matrix a, matrix b, matrix c)
{
  int i, j, k;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      a[i][j] = 0.0;
      for (k = 0; k < N; k++)
        a[i][j] += b[i][k] * c[k][j];
    }
  }
}
