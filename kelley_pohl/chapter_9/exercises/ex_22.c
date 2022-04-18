
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned b1:2, b2:2, b3:2, b4:2, b5:2;
} booleans;

int main(void)
{
  booleans b = {0, 0, 0, 0, 0};
  int      cnt = 0;

  printf("\n%5s%7s%7s%7s%7s%7s%7s%7s%11s\n\n",
         "Cnt", "b.b1", "b.b2", "b.b3", "b.b4", "b.b5",
         "fct1", "fct2", "Majority");
  for (b.b1 = 0; b.b1 < 2; ++(b.b1))
    for (b.b2 = 0; b.b2 < 2; ++(b.b2))
      for (b.b3 = 0; b.b3 < 2; ++(b.b3))
        for (b.b4 = 0; b.b4 < 2; ++(b.b4))
          for (b.b5 = 0; b.b5 < 2; ++(b.b5))
                    printf("%5d%7d%7d%7d%7d%7d" \
                           "%6d%7d%9d\n",
                           ++cnt, b.b1, b.b2, b.b3,
                           b.b4, b.b5,
                           b.b1 || b.b3 || b.b5,
                           ((b.b1 && b.b2) ||
                            (b.b4 && b.b5)),
                           b.b1 + b.b2 + b.b3 +
                           b.b4 + b.b5 >= 3);


  putchar('\n');
  return EXIT_SUCCESS;
}
