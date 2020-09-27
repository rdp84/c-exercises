
#include <stdio.h>
#include <stdlib.h>

#define GREETINGS(a, b, c) \
  printf(#a ", " #b ", and " #c ": Hello!\n")

int main(void)
{

  /* 
     This should cause:
     Alice, Bob and Carole: Hello!
     to be printed.
     
     GREETINGS will be replaced with the printf... statememnt. With the -E
     option should see that the definition of GREETINGS is removed.
   */
  GREETINGS(Alice, Bob, Carole);
  return EXIT_SUCCESS;
}
