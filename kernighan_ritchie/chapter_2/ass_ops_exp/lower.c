#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int
main(void)
{
  char a = 'A';
  printf("a: %c\na: %c\n", a, lower(a));
  
  return EXIT_SUCCESS;
}

/* lower: convert c to lower case; ASCII only */
int
lower(int c)
{
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
