#include <stdio.h>
#include "example4.h"

int main(void) {
  char str[] = "Reverse me";
  reverse(str);
  printf("%s\n", str);
  return 0;
}
