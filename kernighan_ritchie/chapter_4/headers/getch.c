#include "calc.h"

char buf[BUFSIZE];
int  bufp = 0;

/* getch: get a (possibly pushed back) character */
int
getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void
ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
