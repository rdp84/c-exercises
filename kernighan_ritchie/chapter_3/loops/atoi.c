#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int my_atoi(char s[]);

int
main(void)
{
  char n[] = "  -24531";
  printf("%d\n", my_atoi(n));

  return EXIT_SUCCESS;
}

/* my_atoi: convert s to integer; version 2 */
int
my_atoi(char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); ++i) /* skip whitespace */
    ;
  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') /* skip sign */
    i++;
  for (n = 0; isdigit(s[i]); ++i)
    n = n * 10 + (s[i] - '0');

  return sign * n;
}
