
#include <stdio.h>

void try_to_change_it(int);

int main(void)
{

  int a = 1;

  printf("%d\n", a);
  try_to_change_it(a);
  printf("%d\n", a);

  return 0;
}

void try_to_change_it(int a)
{
  a = 777;
}
