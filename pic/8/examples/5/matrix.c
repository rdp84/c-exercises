#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

/*
 * The following matrix, A:
 *
 * ---------------
 * | 0   1   4   |
 * | 9   16  25  |
 * | 36  49  64  |
 * | 81  100 121 |
 * ---------------
 *
 * is stored in memory like:
 *
 * Address | 0 | 1 | 2 | 3 | 4  | 5  | 6  | 7  | 8  | 9  | 10  | 11  |
 * --------|----------------------------------------------------------
 * Value   | 0 | 1 | 4 | 9 | 16 | 25 | 36 | 49 | 64 | 81 | 100 | 121 |
 *
 * A(i,j) is at address (3 * i) + j (0 based)
 * e.g., A(2,1) = 49, at address 7
 * e.g., A(3,1) = 100, at address 10
 */


double *create_matrix(void) {
  int i, j;
  double *retValue;

  retValue = malloc(SIZE * SIZE * sizeof(double));

  srand(time(NULL));
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      retValue[dim(i, j)] = rand() % 19 - 9;
    }
  }

  return retValue;
}

void free_matrix(double *a) {
  free(a);
}

double *add_transpose(double *a, double *b) {
  int i, j;
  double *retValue;

  retValue = malloc(SIZE * SIZE * sizeof(double));

  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      /*
      * The successive accesses to a(i,j) will go sequentially in memory
      * The successive accesses to b(j,i) will jump SIZE elements at a time
      * a has a favourable traversal, b is "jumpy"
      */
      retValue[dim(i, j)] = a[dim(i, j)] + b[dim(j, i)];
    }
  }

  return retValue;
}

/*
 * Change the traversal order
 * Each nested iteration is acting on the same n * n submatrix,
 * a cache miss on one lookup will bring memory into cache for the other
 * lookup
 */
double *add_transpose_blocked(double *a, double *b, int bsize) {
  int i, j, ii, jj;
  double *retValue;

  retValue = malloc(SIZE * SIZE * sizeof(double));

  /*
   * Doubly-nested loop goes to quadruply-nested loop
   * Increment i and j by bsize at a time
   */
  for (i = 0; i < SIZE; i += bsize) {
    for (j = 0; j < SIZE; j += bsize) {
      /* Do a little iteration over the submatrix with ii and jj */
      for (ii = i; ii < i + bsize; ii++) {
        for (jj = j; jj < j + bsize; jj++) {
          retValue[dim(ii, jj)] = a[dim(ii, jj)] + b[dim(jj, ii)];
        }
      }
    }
  }

  return retValue;
}

void print_matrix(double *a) {
  int i, j;

  for(i = 0; i < SIZE; i++) {
    printf("| ");
    for (j = 0; j< SIZE; j++) {
      printf("%6.1f", a[dim(i, j)]);

    }
    printf(" |\n");
  }
  printf("\n");
}
