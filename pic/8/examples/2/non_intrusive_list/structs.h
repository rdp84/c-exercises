#ifndef STRUCTS_H
#define STRUCTS_H

struct Complex {
  double re;
  double im;
};
typedef struct Complex Complex;
typedef Complex* Complex_t;
Complex_t complex_cons(double, double);

struct Coord {
  int x;
  int y;
};
typedef struct Coord Coord;
typedef Coord* Coord_t;
Coord_t coord_cons(int, int);

#endif
