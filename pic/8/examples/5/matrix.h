#ifndef MATRIX_H
#define MATRIX_H

#define SIZE 10
#define dim(i, j) (((i) * SIZE) + (j))

double *create_matrix(void);
void free_matrix(double *);
void print_matrix(double *);
double *add_transpose(double *, double *);
double *add_transpose_blocked(double *, double *, int);

#endif
