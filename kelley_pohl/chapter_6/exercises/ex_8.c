#include <stdio.h>

typedef   unsigned long ulong;

int
main(void)
{
  char         *pc  = NULL;
  int          *pi  = NULL;
  double       *pd  = NULL;
  long double  *pld = NULL;

  /*
   * Combination of pointer arithmetic and conversion to numerical address
   * All pointers point to NULL. Each pointer is offset by 1 and then we take then
   * numerical address. So for *pc, a char is 1 byte so the offset simply increments to
   * 1 which gives a numerical address of 1. For (pld + 3) then *pld is 16 bytes so an offset
   * of 3 is 48 bytes.
   */

  printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
         (ulong) (pc + 1), (ulong) (pi + 1),
         (ulong) (pd + 1), (ulong) (pld + 1),
         (ulong) (pc + 3), (ulong) (pld + 3));

  return 0;
}
