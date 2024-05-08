#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* Heap allocate array */
  char *s = malloc(sizeof(char) * 10);
  /* Array is free */
  free(s);
  /* Array is double freed */
  free(s);
  printf("%s\n", s);
  return 0;
}
