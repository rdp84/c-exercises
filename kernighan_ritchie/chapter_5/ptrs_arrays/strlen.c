#include <stdio.h>
#include <stdlib.h>

int _strlen(char *);

int
main(void)
{
  char s[] = "hello, world";
  printf("_strlen(s): %d\n", _strlen(s));
  return EXIT_SUCCESS;
}

/* strlen: return length of string s */
int
_strlen(char *s)
{
  int n;

  for(n = 0; *s != '\0'; s++)
    n++;
  return n;
}
