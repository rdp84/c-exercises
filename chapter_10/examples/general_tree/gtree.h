
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
  int         child_no;
  DATA        d;
  struct node *sib;
};

typedef struct node NODE;
typedef NODE        *GTREE;

struct pair {
  int out;
  int in;
};

typedef struct pair PAIR;

void  preorder_g(GTREE, int);
GTREE new_gnode(void);
GTREE init_gnode(DATA, int, GTREE);
void  buildtree(PAIR [], DATA [], int, GTREE []);
