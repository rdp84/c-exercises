#include "getfloat.h"

/* getfloat: get next float from input into *pn */
int
getfloat(double *pn)
{
  double power;
  int c, d, sign;

  while (isspace(c = getch()))   /* skip whitespace */
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);                  /* its not a number */
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    d = c;
    if (!isdigit(c = getch())) {
      if (c != EOF)
        ungetch(c);             /* push back non-digit */
      ungetch(d);               /* push back sign char */
      return d;                 /* return sign char    */
    }

  }
  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');
  if (c == '.')
    c = getch();
  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }

  *pn = sign * *pn / power;

  if (c != EOF)
    ungetch(c);
  return c;
}
