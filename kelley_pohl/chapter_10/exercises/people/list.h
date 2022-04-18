
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[10];
  int  age;
  int  weight;
} DATA;

struct linked_list {
  DATA               d;
  struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT            *LINK;

enum compare_by {age, name};
typedef enum compare_by compare_by;

LINK   create_l(DATA [], int);
void   delete_list(LINK);
void   print_list(LINK);

int    count(LINK);
int    count_weight_age(LINK, int, int);

void   concatenate(LINK, LINK);
void   insert(LINK, LINK, LINK);


int    compare(DATA *, DATA *, compare_by);
void   sort(LINK, compare_by,
            int (*f)(DATA *, DATA *, compare_by));

void   sort_age(LINK);
void   sort_name(LINK);

void swap(LINK, LINK);
