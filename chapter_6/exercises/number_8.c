
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;

int main(void)
{
  char        *pc  = NULL;
  int         *pi  = NULL;
  double      *pd  = NULL;
  long double *pld = NULL;

  /* 
     All pointers intially point to NULL which has address 0.
     With the pointer arithmetic (adding 1 and 3) it ends up pointing to the next
     variable of the same type; in terms of memory locations this will be the size
     of that type away. So for (pc + 1) that is the next char which is 1 byte away,
     (pi + 1) is the next int which is 4 bytes away, (pd + 1) is the next double
     which 8 bytes away etc.
   */
  
  printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
         (ulong)(pc + 1), (ulong)(pi + 1),
         (ulong)(pd + 1), (ulong)(pld + 1),
         (ulong)(pc + 3), (ulong)(pld + 3));

  return EXIT_SUCCESS;
}
