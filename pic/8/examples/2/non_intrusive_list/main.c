#include <stdlib.h>
#include "structs.h"
#include "list.h"

/*
 * The list we have is a non-intrusive list, i.e., the data we hold
 * is pointed to by a pointer. We use void * for genericity, similar
 * to the Java implementation of a linked list
 * The problem is that we have now introduced pointer indirections
 * which are expensive; memory lookup for the pointer itself and
 * then another for the data, causing the CPU to stall twice.
 * Prediction plays a big part; if the pointer has not been changed
 * or changed in predictable ways then CPU can work ahead of time,
 * figure out what the pointer value is going to be and load the address into cache.
 */

int main(void) {
  Complex_t complex = complex_cons(1.0, 2.0);
  Coord_t coord = coord_cons(1, 2);

  List_t myList = cons_list(complex, NULL);
  myList->tail = cons_list(coord, NULL);
  print_list(myList);

  free(complex);
  free(coord);
  free(myList->tail);
  free(myList);
  
  return 0;
}
