#include <stdio.h>
#include <stdlib.h>

int strend(char *, char *);

int
main(void)
{
  char s[] = "hello, world";
  char t[] = "llo,";

  printf("strend(s, t): %d\n", strend(s, t));
  
  return EXIT_SUCCESS;
}

/* strend: return 1 if string t occurs at the end of s */
int
strend(char *s, char *t)
{
  while (*s != *t && *s) /* find position in s which matches first char in t */
    s++;
  if (*s == '\0')        /* check we did find a match and not the end of s */
    return 0;
  while (*++s == *++t)   /* check all subsequent characters */
    if (*s == '\0')
      return 1;
  return 0;
}
