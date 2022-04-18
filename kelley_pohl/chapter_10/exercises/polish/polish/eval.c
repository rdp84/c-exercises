
#include "polish.h"

int evaluate(stack *polish)
{
  data  d, d1, d2;
  stack eval;

  initialize(&eval);
  while(!empty(polish)) {
    d = pop(polish);

    switch (d.kind) {
    case value:
      push(d, &eval);
      break;
    case operator:
      /*
         d1 is the second pop since the stack is a
         LIFO data structure so when evaluating the
         expression d1 is the second position.
         This will cause issues with '-' operand
       */
      d2 = pop(&eval);
      d1 = pop(&eval);
      d.kind = value;

      switch (d.u.op) {
      case '+':
        d.u.val = d1.u.val + d2.u.val;
        break;
      case '-':
        d.u.val = d1.u.val - d2.u.val;
        break;
      case '*':
        d.u.val = d1.u.val * d2.u.val;
      }
      push(d, &eval);
    }
  }
  d = pop(&eval);
  return d.u.val;
}
