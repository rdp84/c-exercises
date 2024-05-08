#include <stdio.h>

int
main(void)
{
  char str[] = "A string.";
  char *pc = str;

  printf("%c %c %c\n", str[0], *pc, pc[3]);
  pc += 2;
  printf("%c %c %c\n", *pc, pc[2], pc[5]);
  
  return 0;
}
