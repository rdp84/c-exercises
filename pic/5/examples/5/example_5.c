#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  /* Stack allocate array */
  int a[10];
  /* Partially initialize it */
  a[2] = 0;
  /* Access it. This might or might not be initialized */
  if (a[argc])
    printf("print something\n");
  return 0;
}
