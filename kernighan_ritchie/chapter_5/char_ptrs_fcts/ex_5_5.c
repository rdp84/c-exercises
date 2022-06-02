#include <stdio.h>
#include <stdlib.h>

void my_strncpy(char *, char *, int);
void my_strncat(char *, char *, int);
int  my_strncmp(char *, char *, int);

int
main(void)
{
  char *t = "Hello, World";
  char s[15];

  char *v = "World";
  char u[15] = "Hello, ";

  char *r = "HelLo, World";

  my_strncpy(s, t, 15);
  printf("my_strncpy(s, t, 15): %s\n", s);
  
  my_strncat(u, v, 8);
  printf("my_strncat(u, v, 8): %s\n", u);

  printf("my_strncmp(r, t, 3): %d\n", my_strncmp(r, t, 3));
  
  return EXIT_SUCCESS;
}

/* my_strncpy: copy n characters from t to s */
void
my_strncpy(char *s, char *t, int n)
{
  while (*t && n-- > 0)
    *s++ = *t++;
  while (n-- > 0)
    *s++ = '\0';
}

/* my_strncat: concatenate n characters from t to the end of s; s must be big enough */
void
my_strncat(char *s, char *t, int n)
{
  while (*s)
    s++;
  while (*t && n-- > 0)
    *s++ = *t++;
  while (n-- > 0)
    *s++ = '\0';
}

/* my_strncmp: compare at most n characters of t with s */
int
my_strncmp(char *s, char *t, int n)
{
  while (*s == *t) {
    if (*s == '\0' || --n == 0)
      return 0;
    s++, t++;
  }
  return *s - *t;
}
