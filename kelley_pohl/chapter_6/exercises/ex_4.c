#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  int i, j, *p, *q;

  p = &i;
  printf("%p\n", p);

  // Valid, address of i, dereference gets the value stored at that address then ampersand gets its address
  //&(*(&i))
  p = &*&i;
  printf("%p\n", p);

  // Invalid, int * is 8 bytes, int is 4 bytes so casting to smaller type
  // i = (int) p;

  // Invalid, &p gives a **int but q is int *
  // q = &p;

  // Invalid, *q is an int, &j is int * so incompatible types
  // *q = &j;

  // Invalid, the paranthesis means *& binds but there is nothing to take the address of (j is outside) 
  // i = (*&)j;

  // Valid, first & gives int * wich is then dereferenced to be int, Second & gives int * which is then derefereced
  i = *&*&j;

  // Valid but possibly undefined. Pointer arithmetic is performed with p++ and then that is dereferenced.
  // This is then added to whatever is stored at *q
  q = &j;
  i = *p++ + *q;
  
  return EXIT_SUCCESS;
}
