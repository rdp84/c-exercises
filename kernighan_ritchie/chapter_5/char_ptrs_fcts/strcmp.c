#include <stdio.h>
#include <stdlib.h>

int strcmp_arrays(char *, char *);

int
main(void)
{
  char *s = "Hello, World";
  char *t = "Hello, World";

  printf("s: %s\nt: %s\nstrcmp(s, t): %d\n", s, t, strcmp_arrays(s, t));
  
  return EXIT_SUCCESS;
}

/* strcmp: return <0 if s < t, 0 if s == t, >0 if s > t  */
int
strcmp_arrays(char *s, char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}
