#include "matrix.h"
#include <stdbool.h>

matrix_t matrix_create(int rows, int cols) { 
  int i, j;
  matrix_t retValue;

  retValue.rows = rows;
  retValue.cols = cols;
  retValue.elts = malloc(rows * cols * sizeof(double));

  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++)
      matrix_set(retValue, i, j, 0.0);

  return retValue;
}

double matrix_get(matrix_t m, int r, int c) { 
  assert(r < m.rows && c < m.cols);
  return m.elts[dim(m, r, c)];
}

void matrix_set(matrix_t m, int r, int c, double d) { 
  assert(r < m.rows && c < m.cols);
  m.elts[dim(m, r, c)] = d;
}

void matrix_free(matrix_t m) { 
  free(m.elts);
}

matrix_t matrix_multiply(matrix_t m1, matrix_t m2) { 
  int i, j, k;
  double d;
  matrix_t retValue;

  retValue = matrix_create(m1.rows, m2.cols);

  for (i = 0; i < m1.rows; i++) {
    for (j = 0; j < m2.cols; j++) {
      for (k = 0; k < m2.rows; k++) {
        d = matrix_get(retValue, i, j) + matrix_get(m1, i, k) * matrix_get(m2, k, j);
        matrix_set(retValue, i, j, d);
      }
    }
  }

  return retValue;
}

matrix_t matrix_transpose(matrix_t m) { 
  int i, j;
  double d;
  matrix_t retValue;

  retValue = matrix_create(m.cols, m.rows);

  for (i = 0; i < m.rows; i++) {
    for (j = 0; j < m.cols; j++) {
      d = matrix_get(m, i, j);
      matrix_set(retValue, j, i, d);
    }
  }

  return retValue;
}

matrix_t matrix_multiply_transposed(matrix_t m1, matrix_t m2) { 
  assert(m1.cols == m2.cols);
  matrix_t m2T, retValue;

  m2T = matrix_transpose(m2);
  retValue = matrix_multiply(m1, m2T);

  matrix_free(m2T);

  return retValue;
}

matrix_t matrix_multiply_fast(matrix_t m1, matrix_t m2) { 
  matrix_t retValue;
  retValue = matrix_multiply_transposed(m1, m2);
  return retValue;
}

void matrix_print(matrix_t m) { 
  for (int i = 0; i < m.rows; i++) { 
    for (int j = 0; j < m.cols; j++) { 
      printf("%g\t", matrix_get(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}
