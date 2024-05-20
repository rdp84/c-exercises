#include <stdlib.h>
#include <stdbool.h>
#ifndef GC_H
#define GC_H 1

struct node {
  int value;
  struct node *left;
  struct node *right;
  bool mark;
  struct node *next;
};
typedef struct node Node;

struct root {
  Node *start;
  struct root *next;
};
typedef struct root Root;

struct alloc {
  Node *nodes;
  Root *roots;
};
typedef struct alloc Alloc;

/* const Node *empty = NULL; */
Alloc *make_allocator(void);
Node *node(int value, Node *left, Node *right, Alloc *a);
Root *root(Node *node, Alloc *a);
void gc(Alloc *a);

#endif
