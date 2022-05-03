#include <stdio.h>
#include <stdlib.h>

int htoi(char s[]);
int mod_16(char c);
int power(int n);

int
main(void)
{
  char hex[] = "4aC";
  printf("hex: %s, int: %d\n", hex, htoi(hex));
  return EXIT_SUCCESS;
}

/* htoi: converts a a hexadecimal string to an integer */
int
htoi(char s[])
{
  char c;
  int i, j, n, unit, pow;

  i = j = n = 0;
  for (i; s[i] != '\0'; ++i)
    ;
  --i;

  for (i; i >= 0 && (((c = s[i]) >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')); --i) {
    unit = mod_16(c);
    pow = power(j);
    n = unit * pow + n;
    ++j;
  }

  return n;
}

/* mod_16: returns modulo 16 of c */
int
mod_16(char c)
{
  if (c > '9')
    return c % 16 + 9;
  else
    return c % 16;
}

/* power: raises 16 to the n-th power; n >= 0 */
int
power(int n)
{
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * 16;
  return p;
}
