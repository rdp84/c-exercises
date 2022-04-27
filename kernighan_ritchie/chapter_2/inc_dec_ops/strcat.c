#include <stdio.h>
#include <stdlib.h>

#define S_LENGTH 20
#define T_LENGTH 10

void str_cat(char s[], char t[]);

int
main(void)
{
  char s[S_LENGTH] = "hello\n";
  char t[T_LENGTH] = "world!";

  printf("%s", s);
  str_cat(s, t);
  printf("%s\n", s);
  
  return EXIT_SUCCESS;
}

/* strcat: concatencate t to end of s; s must be big enough */
void
str_cat(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0')               /* find end of s */
    i++;
  while ((s[i++] = t[j++]) != '\0')  /* copy t */
    ;
}
