
#include <stdio.h>

typedef struct {
  char                    *name;
  enum {red, white, blue} colour;
} flower;

typedef struct {
  char *name;
  int  calories;
} fruit;

typedef struct {
  char *name;
  int  calories;
  int  cooking_time; /* in minutes */
} vegetable;

typedef union {
  flower    flw;
  fruit     frt;
  vegetable veg;

} flower_fruit_or_vegtable;
