#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 32

void itoa(int, char []);

int
main(void)
{
  char s[MAXSIZE];
  itoa(123, s);
  printf("s: %s\n", s);
  return EXIT_SUCCESS;
}

void
itoa(int n, char s[])
{
  static int i = 0;
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }
  if (n / 10)
    itoa(n / 10, s);
  s[i++] = abs(n) % 10 + '0';
  s[i] = '\0';
}
