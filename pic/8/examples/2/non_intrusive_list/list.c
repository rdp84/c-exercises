#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "structs.h"

List_t cons_list(void *data, List_t tail) {
  List_t retValue = (List_t) malloc(sizeof(List));
  retValue->data = data;
  retValue->tail = tail;
  return retValue;
}

void print_list(List_t list) {
  if (list == NULL)
    return;
  else {
    Coord_t coord = (Coord_t) list->data;
    printf("x: %d, y: %d\n", coord->x, coord->y);
    print_list(list->tail);
  }
}
