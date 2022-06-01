#include <stdio.h>
#include <stdlib.h>

void strcpy_arrays(char *, char *);
void strcpy_ptrs_1(char *, char *);
void strcpy_ptrs_2(char *, char *);
void strcpy_ptrs_3(char *, char *);

int
main(void)
{
  char *t = "Hello, World";
  char s[13], u[13], v[13], w[13];

  printf("t: %s\n", t);
  strcpy_arrays(s, t);
  printf("s: %s\n", s);

  strcpy_ptrs_1(u, t);
  printf("u: %s\n", u);

  strcpy_ptrs_2(v, t);
  printf("v: %s\n", v);

  strcpy_ptrs_3(w, t);
  printf("w: %s\n", w);
  
  return EXIT_SUCCESS;
}

/* strcpy: copy t to s; array subscript version */
void
strcpy_arrays(char *s, char *t)
{
  int i;

  i = 0;
  while((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy: copy t to s; pointer version 1 */
void
strcpy_ptrs_1(char *s, char *t)
{
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

/* strcpy: copy t to s; pointer version 2 */
void
strcpy_ptrs_2(char *s, char *t)
{
  while ((*s++ = *t++) != '\0')
    ;
}

/* strcpy: copy t to s; pointer version 3 */
void
strcpy_ptrs_3(char *s, char *t)
{
  while ((*s++ = *t++))
    ;
}
