#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>     /* for math functions */
#include <string.h>   /* string comparison */

#define MAXOP   100   /* max size of operand or operator */
#define NUMBER  '0'   /* signal that a number was found */
#define NAME    'n'   /* signal that function name was found */

int    getop(char []);
void   push(double);
double pop(void);
void   mathfn(char []);

/* reverse Polish calculator */
int
main(void)
{
  int    type;
  double op2;
  char   s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case NAME:
      mathfn(s);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return EXIT_SUCCESS;
}

#define MAXVAL  100  /* maximum depth of val stack */

int    sp = 0;       /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto stack */
void
push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double
pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* mathfn: perform math function on elements, pushing result to the top */
void
mathfn(char s[])
{
  double op1, op2;
  
  if (strcmp(s, "pow") == 0) {
    op2 = pop();
    op1 = pop();
    push(pow(op1, op2));
  }
  else if (strcmp(s, "sin") == 0) {
    op1 = pop();
    push(sin(op1));
  }
  else if (strcmp(s, "cos") == 0) {
    op1 = pop();
    push(cos(op1));
  }
  else if (strcmp(s, "tan") == 0) {
    op1 = pop();
    push(tan(op1));
  }
  else if (strcmp(s, "exp") == 0) {
    op1 = pop();
    push(exp(op1));
  }
  else {
    printf("error: unrecognised function %s\n", s);
  }
}

#include <ctype.h>

int  getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int
getop(char s[])
{
  int i, c, ret;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  i = 0;
  if (!isdigit(c) && c != '.') {
    if (isalpha(c)) {   /* collect function name */
      while(isalpha(s[++i] = c = getch()))
        ;
      if (strlen(s) > 1)
        ret = NAME;     /* >1 char; it is NAME  */
      else
        return c;       /* it may be a command */
    }
    else
      return c;         /* operator */
  }
  else {
    if (isdigit(c))     /* collect integer part */
      while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.')       /* collect fraction part */
      while (isdigit(s[++i] = c = getch()))
        ;
    ret = NUMBER;
  }
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);

  return ret;
}

#define BUFSIZE  100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

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
