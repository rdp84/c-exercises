#include <stdio.h>

char *unary(unsigned short);

/* The value of a pointer to an object whose lifetime has ended is used */

int main(void) {
  printf("%s\n", unary(6));
  return 0;
}

char *unary(unsigned short s) {
  char local[s+1];
  int i;

  for (i = 0; i< s; i++)
    local[i] = '1';
  local[s] = '\0';

  return local;
}
