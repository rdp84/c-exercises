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
  char u[13] = "Hello, ";

  char *r = "HelLo, World";

  my_strncpy(s, t, 15);
  printf("my_strncpy(s, t, 15): %s\n", s);
  
  my_strncat(u, v, 5);
  printf("my_strncat(u, v, 5): %s\n", u);

  printf("my_strncmp(r, t, 3): %d\n", my_strncmp(r, t, 3));
  
  return EXIT_SUCCESS;
}

/* my_strncpy: copy n characters from t to s
   If there's no null byte amongst first n bytes of t, no null byte it written to s
   If t is less than n, pad s with null bytes to ensure n bytes are written
 */
void
my_strncpy(char *s, char *t, int n)
{
  while (*t && n-- > 0)
    *s++ = *t++;
  while (n-- > 0)
    *s++ = '\0';
}

/* my_strncat: concatenate at most n bytes from t to the end of s 
   s will always be null terminated, therefore it needs to be strlen(s) + n + 1 in size.
*/
void
my_strncat(char *s, char *t, int n)
{
  while (*s)
    s++;
  while (*t && n-- > 0)
    *s++ = *t++;
  *s = '\0';
}

/* my_strncmp: compare at most n bytes of t with s */
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
