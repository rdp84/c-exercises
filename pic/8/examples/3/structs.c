#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

Data *iota_array(int n) {
  int i;

  printf("Sizeof struct Data: %lu\n", sizeof(Data));
  Data *a = malloc(n * sizeof(Data));
  for (i = 0; i < n; i++) {
    a[i].i = i;
    a[i].d = 1.0;
    a[i].c = 'x';
  }

  return a;
}

/*
 * Only modifying character field c. We have to "hop over"
 * the integer and double fields, meaning characters are at least
 * 12 and probably 16 bytes apart. This means only 4 characters in
 * each cache line. Optimally we would want 64 characters in each line.
 */
void traverse(int n, Data *a) {
  int i;

  for (i = 0; i < n; i++)
    a[i].c += 'y';
}

void print_vector(int n, Data *a) {
  int i;

  for (i = 0; i < n; i++)
    printf("{ i: %d, d: %f, c: %c }\n", a[i].i, a[i].d, a[i].c);
}
