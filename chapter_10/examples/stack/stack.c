/* The basic stack routines */

#include "stack.h"

void initialize(stack *stk)
{
  stk->cnt = 0;
  stk->top = NULL;
}

void push(data d, stack *stk)
{
  elem *e;

  e = malloc(sizeof(elem));
  e->d = d;
  e->next = stk->top;

  stk->cnt++;
  stk->top = e;
}

data pop(stack *stk)
{
  data d;
  elem *e;

  d = stk->top->d;
  e = stk->top;

  stk->cnt--;
  stk->top = stk->top->next;
  free(e);

  return d;
}

data top(stack *stk)
{
  return stk->top->d;
}

boolean empty(const stack *stk)
{
  return ((boolean) stk->cnt == EMPTY);
}

boolean full(const stack *stk)
{
  return ((boolean) stk->cnt == FULL);
}
