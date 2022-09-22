#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *f;

  f = fopen("/etc/passwd", "r");
  int c1 = getc(f);
  int c2 = getc(f);
  int c3 = getc(f);
  int c4 = getc(f);

  printf("%c%c%c%c\n", c1, c2, c3, c4);
  fclose(f);
  return EXIT_SUCCESS; 
}
