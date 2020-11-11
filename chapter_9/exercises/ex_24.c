
#include <stdio.h>
#include <stdlib.h>

struct test {
  unsigned a:1, b:2, c:3;
};

int main(void)
{
  int          i;
  struct test  x;

  for (i = 0; i < 23; ++i) {

    /*
       With the following assignment:
       x.a = x.b = x.c = i;

       then a will overflow once i > 1 and therefore
       flip between 0 & 1 on each interation
       similar with b, it will overflow once i > 3 and
       flip between 0, 1, 2, 3
       c will overflow once i > 7 and flip between
       0, 1, 2, 3, 4, 5, 6, 7
    */

    /*
    x.a = x.b = x.c = i;
    printf("x.a = %d  x.b = %d  x.c = %d\n",
           x.a, x.b, x.c);
    */

    /*
      With the following assignment:
      x.c = x.b = x.a = i;

      then a will overflow once i > 1 and since b & c
      are assigned to this value then they will also
      flip between 0 & 1.
    */

    x.c = x.b = x.a = i;
    printf("x.a = %d  x.b = %d  x.c = %d\n",
           x.a, x.b, x.c);
  }

  return EXIT_SUCCESS;
}
