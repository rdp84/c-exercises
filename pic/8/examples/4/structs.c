#include <stdlib.h>
#include "structs.h"

DataVec *iota_array(int n) {
  int i;

  DataVec *retValue = malloc(sizeof(DataVec));
  retValue->is = malloc(n * sizeof(int));
  retValue->ds = malloc(n * sizeof(double));
  retValue->cs = malloc(n * sizeof(char));

  for (i = 0; i < n; i++) {
    retValue->is[i] = i;
    retValue->ds[i] = 1.0;
    retValue->cs[i] = 'x';
  }
  
  return retValue;
}

void traverse(int n, DataVec *a) {
  int i;
  char *cs = a->cs;

  for (i = 0; i < n; i++)
    cs[i] += 'y';
}

void free_vec(DataVec *a) {
  free(a->is);
  free(a->ds);
  free(a->cs);
  free(a);
}
