#include <stdlib.h>
#include <stdio.h>
#include "coord.h"
#include "complex.h"

/*
 * The list we have is a intrusive list, i.e., the data is contained
 * in the list itself.
 * This means we have removed the pointer indirections and the performance
 * cost of those. However we now have specialized representations of a
 * list and coan no longer use generic linked list routines.
 * There is also a performance hit because following a tail pointer
 * can lead to a cache miss. Each cell in the list contains a tail
 * pointer which reduces the number of data elemenets that can fit
 * in a cache line, which decreases data density and increases
 * cache miss rate.
 */

int main(void) {
  Coord coord = cons_coord(1, 2);
  CoordList_t coordList1 = cons_coord_list(coord);

  coord = cons_coord(3, 4);
  CoordList_t coordList2 = cons_coord_list(coord);
  coordList2->tail = coordList1;

  print_coord_list(coordList2);
  free_coord(coordList2);

  Complex complex = cons_complex(1.0, 2.0);
  ComplexList_t complexList1 = cons_complex_list(complex);

  complex = cons_complex(3.0, 4.0);
  ComplexList_t complexList2 = cons_complex_list(complex);
  complexList2->tail = complexList1;

  print_complex_list(complexList2);
  free_complex(complexList2);
  
  return 0;
}
