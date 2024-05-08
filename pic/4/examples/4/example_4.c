#include <stdio.h>

int main(void) {
  int i = 2;
  // grey (or gray) expression. Compiler dependent as to what is printed
  int j = i++ + ++i;

  printf("%d %d\n", i, j); // prints 4 6 on M1

  return 0;
}
