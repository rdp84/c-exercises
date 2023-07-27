#include "calc.h"

int    sp = 0;
double val[MAXVAL];

/* push: push f onto stack */
void
push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error: stack full, can't push %g\n", f);
    error = 'E';
  }
}

/* pop: pop and return top value from stack */
double
pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    error = 'E';
    return 0.0;
  }
}

/* clear: clears the stack */
void
clear(void)
{
  sp = 0;
}
