#include <stdio.h>
#include <stdlib.h>

int strcmp_arrays(char *, char *);
int strcmp_ptrs_1(char *, char *);
int strcmp_ptrs_2(char *, char *);

int
main(void)
{
  char *s = "Hello, WOrld";
  char *t = "HeLlo, World";

  printf("s: %s\nt: %s\nstrcmp_arrays(s, t): %d\n", s, t, strcmp_arrays(s, t));
  printf("s: %s\nt: %s\nstrcmp_ptrs_1(s, t): %d\n", s, t, strcmp_ptrs_1(s, t));
  printf("s: %s\nt: %s\nstrcmp_ptrs_2(s, t): %d\n", s, t, strcmp_ptrs_2(s, t));
  
  return EXIT_SUCCESS;
}

/* strcmp: return <0 if s < t, 0 if s == t, >0 if s > t; array subscript version */
int
strcmp_arrays(char *s, char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp: return <0 if s < t, 0 if s == t, >0 if s > t; pointer version 1 */
int
strcmp_ptrs_1(char *s, char *t)
{

  for(; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

/* strcmp: return <0 if s < t, 0 if s == t, >0 if s > t; pointer version 2 */
int
strcmp_ptrs_2(char *s, char *t)
{
  while (*s == *t) {
    if (*s == '\0')
      return 0;
    s++, t++;
  }
  return *s - *t;
}
