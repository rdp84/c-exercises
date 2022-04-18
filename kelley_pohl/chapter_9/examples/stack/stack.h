
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define EMPTY   -1
#define FULL    (MAX_LEN - 1)

typedef enum boolean {false, true} boolean;

typedef struct stack {
  char s[MAX_LEN];
  int  top;
} stack;

void    reset(stack *);
void    push(char, stack *);
char    pop(stack *);
char    top(const stack *);
boolean empty(const stack *);
boolean full(const stack *);
