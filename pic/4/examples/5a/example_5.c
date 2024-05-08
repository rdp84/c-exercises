#include <stdio.h>

char *unary(unsigned short s) {
  char local[s+1];
  int i;

  for (i = 0; i < s; i++)
    local[i] = 'i';
  local[s] = '\0';

  return local;
}

int main(void) {
  // prints something random since pointer returned is a stack address
  printf("%s\n", unary(6));
  return 0;
}
