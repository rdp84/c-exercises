/* A linked list implementation of a stack */

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL  1000

typedef char               data;
typedef enum {false, true} boolean;

/* An element on the stack */
struct elem {
  data        d;
  struct elem *next;
};

typedef struct elem elem;

struct stack {
  int  cnt;  /* a count of the elements */
  elem *top; /* ptr to the top element */
};

typedef struct stack stack;

void    initialize(stack *);
void    push(data, stack *);
data    pop(stack *);
data    top(stack *);
boolean empty(const stack *);
boolean full(const stack *);
