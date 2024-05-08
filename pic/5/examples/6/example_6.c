#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  /* Heap allocate array */
  int *a = malloc(sizeof(int) * 10);
  /* partially initialize it */
  a[2] = 0;
  /* Access it. This might or might not be intialized */
  if (a[argc]) 
    printf("print something\n");
  free(a);
  return 0;
}
