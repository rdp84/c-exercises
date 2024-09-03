#include <stdlib.h>
#include <stdio.h>
#include "coord.h"

Coord cons_coord(int x, int y) {
  Coord coord;
  coord.x = x;
  coord.y = y;

  return coord;
}

CoordList_t cons_coord_list(Coord coord) {
  CoordList_t retValue = malloc(sizeof(CoordList));
  retValue->data = coord;
  retValue->tail = NULL;

  return retValue;
}

void print_coord_list(CoordList_t list) {
  if (list == NULL) {
    return;
  } else {
    printf("x: %d, y: %d\n", list->data.x, list->data.y);
    print_coord_list(list->tail);
  }
}

void free_coord(CoordList_t list) {
  if (list == NULL) {
    return;
  } else {
    free_coord(list->tail);
    free(list);
  }
}
