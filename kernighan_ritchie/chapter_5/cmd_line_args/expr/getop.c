#include "calc.h"

/* getop: get next operator or numeric operand from the command-line argument */
int
getop(char *arg, char s[])
{
  int i, c;

  s[0] = c = *arg;
  s[1] = '\0';

  i = 0;
  if (!isdigit(c) && c != '.' && c != '-')
    return c;        /* not a number */
  if (c == '-') {
    if (isdigit(c = *++arg) || c == '.')
      s[++i] = c;    /* negative number */
    else {
      if (c != EOF)
        ungetch(c);
      return '-';    /* minus sign */
    }
  }
  if (isdigit(c))    /* collect integer part */
    while (isdigit(s[++i] = c = *++arg))
      ;
  if (c == '.')      /* collect fraction part */
    while (isdigit(s[++i] = c = *++arg))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}
