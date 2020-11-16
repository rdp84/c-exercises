
#include "polish.h"

void fill(stack *stk, const char *str)
{
  const char  *p = str, *p2;
  char        c1, c2, *unary;
  data        d;
  stack       tmp;

  initialize(stk);
  initialize(&tmp);

  /* First process the string and push data onto tmp */
  while (*p != '\0') {
    while (isspace(*p) || *p == ',')
      ++p;

    /* '-' or '+' operators could be unary or binary */
    if ((c1 = *p) == '+' || c1 == '-') {

      /* Advance to the next operator or operand */
      p2 = p + 1;
      while (isspace(*p2) || *p2 == ',')
        ++p2;

      /*
        For c1 to be a unary operator it must
        immediately be followed by a number.

        If it is followed by another operator then
        it must be binary since it has no number
        to associate with.
      */
      if ((c2 = *p2) == '+' || c2 == '-'
          || c2 == '*' || c2 == '/' || c2 == '\0') {
        d.kind = operator;
        d.u.op = c1;
      }
      /*
        c1 is a unary operator so add value and
        and continue parsing from c2
      */
      else {
        d.kind = value;
        unary = malloc(2 * sizeof(char));
        *unary = c1;
        *(unary + 1) = c2;
        assert(sscanf(unary, "%d", &d.u.val) == 1);
        p = p2;
        free(unary);
      }
    }
    /* '*' or '/' operators are binary */
    else if (c1 == '*' || c1 == '/') {
      d.kind = operator;
      d.u.op = c1;
    }
    /* Left with just a operand */
    else {
      d.kind = value;
      assert(sscanf(p, "%d", &d.u.val) == 1);
    }

    if (!full(&tmp))
      push(d, &tmp);          /* push data on tmp */

    while (*p != ',' && *p != '\0')
      ++p;
  }
  reverse(&tmp, stk);
}
