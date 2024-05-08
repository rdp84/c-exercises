#include <stdio.h>
#include <stdlib.h>

// One deallocation per path
int main(void) {
  int *pi = malloc(sizeof(int));
  scanf("%d", pi); // Read an int
  if (*pi % 2) {
    printf("Odd!\n");
    free(pi);     // WRONG! Fails to deallocate pi if *pi is even
  }
  // free(pi); OK! Moving it ensure it always runs
}
