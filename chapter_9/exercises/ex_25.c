
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct {
    int a:3, b:4;
 } x;
*/

struct test {
  int a:3, b:4;
};

typedef struct test t;

int main(void)
{
  t x = {0};
  for (; ;)
    printf("x.a = %2d    x.b = %2d\n", x.a++, x.b++);

  return EXIT_SUCCESS;
}
