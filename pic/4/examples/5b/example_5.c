#include <stdio.h>

char global[10];

char *unary(unsigned short s) {
  char local[s+1];
  char *p = s%2 ? global : local;
  int i;

  for(i = 0; i < s; i++)
    p[i] = '1';
  p[s] = '\0';

  return p;
}

int main(void) {
  printf("%s\n", unary(7));
  return 0;
}
