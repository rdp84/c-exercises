#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE  1000 /* maximum input line length */
#define MAXOP    100  /* max size of operand */

int    get_line(char [], int);
void   push(double);
double pop(void);

int
main(void)
{
  char   line[MAXLINE], operand[MAXOP];
  int    i, j;
  double op2;

  while (get_line(line, MAXLINE) > 0) { /* start processing a line */
    i = 0;
    while (line[i] != '\0') { 
      if (line[i] == '+')
        push(pop() + pop());
      else if (line[i] == '*')
        push(pop() * pop());
      else if (line[i] == '-') {
        op2 = pop();
        push(pop() - op2);
      }
      else if (line[i] == '/') {
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
      }
      else if (line[i] == '\n')
        printf("\t%.8g\n", pop());
      else if (isdigit(line[i]) || line[i] == '.') {
        j = 0;
        while (isdigit(line[i]) || line[i] == '.')
          operand[j++] = line[i++];
        operand[j] = '\0';
        // printf("operand: %s\n", operand);
        push(atof(operand));
      }
      i++;
    }
  }

  return EXIT_SUCCESS;
}

/* get_line: get line into s, return length */
int
get_line(char s[], int lim)
{
  int i, c;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = '\n';
  s[i] = '\0';
  return i;
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
