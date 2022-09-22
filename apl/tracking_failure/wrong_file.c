#include <stdio.h>
#include <stdlib.h>

/*
  Our program would inevitable fail if asked to read from a
  non-existent file. The compiler wouldn't tell us this so
  we'll need to manually add some handling.
  Other languages might be able to warn us that something
  should never be null, e.g., the argument to getc and
  therefore provide us with an opportunity to add handling code,
  removing the compile time warning.
 */
int main(void) {
  FILE *f;

  /* non-existent file! */
  f = fopen("/etc/password", "r");

  /* what just happened */
  if (f == NULL)
    printf("f is NULL\n");
  else
    printf("f is not NULL\n");

  printf("Before reading first character\n");
  int c1 = getc(f); /* segmentation fault! */
  printf("Before reading second character\n");
  int c2 = getc(f);
  printf("Before reading third character\n");
  int c3 = getc(f);
  printf("Before reading fourth character\n");
  int c4 = getc(f);

  printf("%c%c%c%c\n", c1, c2, c3, c4);
  fclose(f);
  return EXIT_SUCCESS; 
}
