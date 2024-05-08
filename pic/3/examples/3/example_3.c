#include <stdio.h>
#include "example_3.h"

int
main(void)
{
  int a[] = {1, 4, 3, 2, 5};
  int *pa = a;
  unsigned int len = 5;
  sort(a, len, inc);

  printf("[");
  while(len--) {
    printf("%d%s", *pa++, len ? " " : "");
  }
  printf("]\n");

  return 0;
}
