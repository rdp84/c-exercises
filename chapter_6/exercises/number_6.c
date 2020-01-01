
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  /* int a = 1, b = 2, c = 3; */
  int a, b, c;

  /*
    Print out addresses of variables.
    The compiler assigns contiguous addresses, separated by 4 bytes
    (since that is the size of an int).
    If the variables are not initialised it makes no difference.
  */

  printf("%s%p\n%s%p\n%s%p\n",
         "&a = ", &a,
         "&b = ", &b,
         "&c = ", &c);

  /*
    In this case we're trying to conver an int * to an int.
    the int * will stores the address of an int - this address
    might be too big to be represented by an int (32-bits, 4 bytes).
    Therefore we may end up with negative numbers.
  */
  /*
  printf("%s%d\n%s%d\n%s%d\n",
         "&a = ", &a,
         "&b = ", &b,
         "&c = ", &c);
  */

  /* Number 7 */
  
  printf("%s%lu\n%s%lu\n%s%lu\n",
         "&a = ", (unsigned long) &a,
         "&b = ", (unsigned long) &b,
         "&c = ", (unsigned long) &c);

  return EXIT_SUCCESS;
}
