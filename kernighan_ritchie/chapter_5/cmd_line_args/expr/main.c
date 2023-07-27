#include "calc.h"

char error = '\0';

/* reverse Polish calculator */
int
main(int argc, char *argv[])
{
  int    type;
  double op1, op2;
  char   s[MAXOP];
  char   *arg;
  
  while (--argc > 0) {
    arg = *++argv;
    type = getop(arg, s);
    switch (type) {
    case NUMBER:
      push(atof(s));
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
      else {
        printf("error: zero divisor\n");
        error = 'E';
      }
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else {
        printf("error: zero divisor\n");
        error = 'E';
      }
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    case '?':  /* print the top element of the stack */
      op2 = pop();
      printf("\t%.8g\n", op2);
      push(op2);
      break;
    case 'd':  /* duplicate top element of the stack */
      op2 = pop();
      push(op2);
      push(op2);
      break;
    case 's':  /* swap the top two elements of the stack */
      op2 = pop();
      op1 = pop();
      push(op2);
      push(op1);
      break;
    case 'c':  /* clear the stack */
      clear();
      break;
    default:
      printf("error: unknown command %s\n", s);
      error = 'E';
      break;
    }

    if (error)
      break;
  }

  if (!error)
    printf("\t%.8g\n", pop());

  return EXIT_SUCCESS;
}

