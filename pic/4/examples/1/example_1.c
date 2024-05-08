#include <stdio.h>

int main(void) {
  int i = 42, j = 28;

  const int *pc = &i; // pointer to a const int. Can also be int const *
  *pc = 41;           // wrong
  pc = &j;

  int *const cp = &i; // const pointer to an int
  *cp = 41;
  cp = &j;            // wrong

  const int *const cpc = &i; // const pointer to a const int
  *cpc = 41;                 // wrong
  cpc = &j;                  // wrong

  return 0;
}
