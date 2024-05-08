#include <stdio.h>

struct values {
  int a;
  int b;
};
typedef struct values values_t;

int main(void)
{
  values_t test2 = {2, 3};
  values_t test1 = {0, 1};

  int *pi = &(test1.a);
  pi += 1;
  printf("%d\n", *pi);
  pi += 2;
  printf("%d\n", *pi);

  return 0;
}
