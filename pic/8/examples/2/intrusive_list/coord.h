#ifndef COORD_H
#define COORD_H

struct Coord {
  int x;
  int y;
};
typedef struct Coord Coord;

struct CoordList {
  Coord data;
  struct CoordList *tail;
};
typedef struct CoordList CoordList;
typedef CoordList* CoordList_t;

Coord cons_coord(int, int);
CoordList_t cons_coord_list(Coord);
void print_coord_list(CoordList_t);
void free_coord(CoordList_t);

#endif
