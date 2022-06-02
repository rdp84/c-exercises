#include <stdio.h>
#include <stdlib.h>

#define SLENGTH 20
#define TLENGTH 10

void str_cat(char *, char *);

int
main(void)
{
  char s[SLENGTH] = "hello";
  char t[TLENGTH] = ", world";

  printf("s: %s\n", s);
  str_cat(s, t);
  printf("s: %s\n", s);

  return EXIT_SUCCESS;
}

/* strcat: concatenate t to end of s; s must be big enough */
void
str_cat(char *s, char *t)
{
  while (*s)            /* find end of s */
    s++;
  while ((*s++ = *t++)) /* copy t */
    ;
}
