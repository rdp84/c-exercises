#include <stdio.h>
#include <stdlib.h>

#define N    3 /* the size of all vectors and matrices */

typedef double   scalar;
typedef scalar   vector[N];
typedef scalar   matrix[N][N];

void   add(vector, vector, vector);
scalar dot_product(vector, vector);
void   multiply(matrix, matrix, matrix);
