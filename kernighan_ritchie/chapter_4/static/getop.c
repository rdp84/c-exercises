#include "calc.h"

/* getop: get next operator or numeric operand */
int
getop(char s[])
{
  int i, c;
  static int lastc = 0;

  if (lastc == 0)
    c = getchar();
  else {
    c = lastc;
    lastc = 0;
  }

  while ((s[0] = c) == ' ' || c == '\t')
    c = getchar();
  s[1] = '\0';
  i = 0;
  if (!isdigit(c) && c != '.' && c != '-')
    return c;        /* not a number */
  if (c == '-') {
    if (isdigit(c = getchar()) || c == '.')
      s[++i] = c;    /* negative number */
    else {
      if (c != EOF)
        lastc = c;
      return '-';    /* minus sign */
    }
  }
  if (isdigit(c))  /* collect integer part */
    while (isdigit(s[++i] = c = getchar()))
      ;
  if (c == '.')    /* collect fraction part */
    while (isdigit(s[++i] = c = getchar()))
      ;
  s[i] = '\0';
  if (c != EOF)
    lastc = c;
  return NUMBER;
}
