
/* A linked list implementation of a Polish stack */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY  0
#define FULL   10000

struct data {
  enum {operator, value} kind;
  union {
    char op;
    int  val;
  } u;
};

typedef struct data        data;
typedef enum {false, true} boolean;

struct elem {
  data        d;
  struct elem *next;
};

typedef struct elem elem;

struct stack {
  int  cnt;
  elem *top;
};

typedef struct stack stack;

boolean empty(const stack *);
int     evaluate(stack *);
void    fill(stack *, const char *);
boolean full(const stack *);
void    initialize(stack *);
data    pop(stack *);
void    prn_data(data *);
void    prn_stack(stack *);
void    push(data, stack *);
data    top(stack *);
