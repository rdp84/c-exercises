
#include <stdio.h>
#include <stdlib.h>

/* 
   Pre-processor stringization operator producses a much simpler/clean output
   with -E option
*/
#define YANK(x)  s = #x

/*
  To get double quotes around an argument can use concatenation but requires nasty
  escaping of characters
 */

//#define YANK(x) s = "\"" x "\"" 

int main(void)
{
  char *s;
  YANK("Go home, Yankee!");
  printf("%s\n", s);

  return EXIT_SUCCESS;
}
