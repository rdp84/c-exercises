#ifndef STRUCTS_H
#define STRUCTS_H

struct data {
  int i;
  double d;
  char c;
};
typedef struct data Data;

/* iota is not an acronym, its the Greek letter that sometimes
 * gets used in math to denote sets of numbers or unit vectors.
 * In this context the function will generate a contiguous
 * series of increasing values of i in the struct
 */
Data *iota_array(int);
void traverse(int, Data *);
void print_vector(int, Data *);

#endif
