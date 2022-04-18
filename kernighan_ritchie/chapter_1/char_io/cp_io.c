#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  int c;

  printf("EOF = %d\n", EOF);
  while (((c = getchar()) != EOF) == 1)
    putchar(c);

  
  return EXIT_SUCCESS;
}
