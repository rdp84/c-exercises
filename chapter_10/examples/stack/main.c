/* Test the stack iplementation by reversing a string */

#include "stack.h"

int main(void)
{
  char  str[] = "My name is Joanna Kelley!";
  int   i;
  stack s;

  printf(" In the string: %s\n", str);

  initialize(&s);
  for ( i = 0; str[i] != '\0'; ++i)
    if (!full(&s))
      push(str[i], &s);

  printf("From the stack: ");
  while (!empty(&s))
    putchar(pop(&s));
  putchar('\n');

  return EXIT_SUCCESS;
}
