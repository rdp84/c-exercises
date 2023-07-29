#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  char *format = "%p %d %d %d\n";
  int  i = 3;
  int  *p = &i;

  /*
   * print address of p, 10, 9, 10
   * first 10 is simple dereferencing the pointer and adding 7, so 3 + 7
   *
   * the 9 is from we get the address of p and dereference it. This gives
   * address of what it points to so when dereferenced again returns 3
   * Therefore we have 3 * 3
   *
   * final 10 is from pointer arithmetic; minus two from p then take
   * that value away from original p which leaves a value of 2
   * multiplying this by 5 gives 10
   */
  printf(format, p, *p + 7, 3 * **&p, 5 * (p - (p - 2)));

  /*
   * Print integer values for p and p - 2.
   * In the expression above I don't think a compiler should warn about
   * integer overflow because it is pointer arithmetic.
   * If you were using the integer values of p and p - 2 then it could
   * potentially be possible if the expression p - 2 became negative
   */

  printf("(unsigned long) p:       %lu\n", ((unsigned long) p));
  printf("(unsigned long) (p - 2): %lu\n", (unsigned long) (p - 2));

  return EXIT_SUCCESS;
}
