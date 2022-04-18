
#include "stack.h"

int main(void)
{
  char  str[] = "My name is Laura Pohl!";
  int   i;
  stack s;

  reset(&s);
  printf(" In the string: %s\n", str);

  for (i = 0; str[i] != '\0'; ++i)
    if (!full(&s))
      push(str[i], &s);

  printf(" From the stack: ");
  while(!empty(&s))
    putchar(pop(&s));
  putchar('\n');

  return EXIT_SUCCESS;
}

void reset(stack *stk)
{
  stk -> top = EMPTY;
}

void push(char c, stack *stk)
{
  stk -> top++;
  stk -> s[stk -> top] = c;
}

char pop(stack *stk)
{
  return stk -> s[stk -> top--];
}

char top(const stack *stk)
{
  return stk -> s[stk -> top];
}

boolean empty(const stack *stk)
{
  return ((boolean) (stk -> top == EMPTY));
}

boolean full(const stack *stk)
{
  return ((boolean) (stk -> top == FULL));
}
