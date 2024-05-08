#include <stdlib.h>

int main(void) {
  /* Array is heap allocated */
  int *a = malloc(sizeof(int) * 100);
  /* Array is free */
  free(a);
  /* Array is dereferenced - DOOM! */
  return a[5];
}
