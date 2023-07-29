#include <stdio.h>

int
main(void)
{
  int a[] = {0, 2, 4, 6, 8}, *p = a + 3;

  /*
   * Textbook has the following snippet

    printf("%s%d%s\n%s%d%s\n",
         "a[?]   = ", *p,       "?",
         "a[?+1] = ", *p + 1, "?");

   * I think it is wanting to print the 4th and 5th
   * element of the array (or whatever offset is used above)
   * The problem is the derefernece binds more tights than the +1
   * so what it actually does is +1 to the 4th element. To get the
   * 5th element need to add brackets around the +1 offset and then
   * dereference
  */

  printf("%s%d%s\n%s%d%s\n",
         "a[?]   = ", *p,       "?",
         "a[?+1] = ", *(p + 1), "?");

  return 0;
}
