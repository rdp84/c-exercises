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
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
