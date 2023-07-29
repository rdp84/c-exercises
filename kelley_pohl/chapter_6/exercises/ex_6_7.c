#include <stdio.h>

int
main(void)
{
  /*
   * int a, b, c;
   * Even if they are not initialized things still work ok
   * and produces the same output, e.g., address difference is 4
   * (4 bytes) for int
   */
  int a = 1, b = 2, c= 3;

  /*
   * Changing to %d produces a compiler warning since %d expects an int (4 bytes)
   * but it is getting a int * (8 bytes)
   */
  printf("%s%p\n%s%p\n%s%p\n",
         "&a = ", &a,
         "&b = ", &b,
         "&c = ", &c);

  // Exercise 7 - print numerical addresses
  printf("%s%lu\n%s%lu\n%s%lu\n",
         "&a = ", (unsigned long) &a,
         "&b = ", (unsigned long) &b,
         "&c = ", (unsigned long) &c);
}
