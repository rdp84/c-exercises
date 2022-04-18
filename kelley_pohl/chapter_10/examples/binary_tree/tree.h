
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
  DATA        d;
  struct node *left;
  struct node *right;
};

typedef struct node NODE;
typedef NODE        *BTREE;

void  inorder(BTREE);
void  preorder(BTREE);
void  postorder(BTREE);
BTREE new_node(void);
BTREE init_node(DATA, BTREE, BTREE);
BTREE create_tree(DATA [], int, int);
