#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim(char s[]);

int
main(void)
{
  int n;
  char s[] = "  a    ";

  printf("%s\n", s);
  n = trim(s);
  printf("%s\n", s);
  printf("%d\n", n);

  char t[] = "     \n     \t";
  printf("%s\n", t);
  n = trim(t);
  printf("%s\n", t);
  printf("%d\n", n);
  
  return EXIT_SUCCESS;
}

int
trim(char s[])
{
  int n;

  for(n = strlen(s) - 1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  s[n + 1] = '\0';

  return n;
}
