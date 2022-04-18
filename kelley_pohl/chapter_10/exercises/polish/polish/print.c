
#include "polish.h"

void prn_data(data *d)
{
  switch (d->kind) {
  case operator:
    printf("%s%3c\n", "kind: operator    op:", d->u.op);
    break;
  case value:
    printf("%s%3d\n", "kind: value      val:", d->u.val);
  }
}

void prn_stack(stack *stk)
{
  data d;

  printf("stack count:%3d%s",
         stk->cnt, (stk->cnt == 0) ? "\n" : "    ");
  if (!empty(stk)) {
    d = pop(stk);     /* pop the data */
    prn_data(&d);     /* print the data */
    prn_stack(stk);   /* recursive call */
    push(d, stk);     /* push the data */
  }
}
