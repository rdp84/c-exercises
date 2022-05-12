#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itob(int n, char s[], int b);
void reverse(char s[]);

int
main(void)
{
  char s[32];
  int  n, b;

  n = 42;
  b = 22;

  itob(n, s, b);
  printf("%s\n", s);

  return EXIT_SUCCESS;
}

/* itob: convert n to characters in s - base b */
void
itob(int n, char s[], int b)
{
  int i, sign, j;

  sign = n;
  i = 0;
  do {
    s[i++] = ((j = abs(n % b)) <= 9) ? j + '0' : j + 'A' - 10;
  } while ((n /= b) != 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

/* reverse: reverse string s in place */
void
reverse(char s[])
{
  int  c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
