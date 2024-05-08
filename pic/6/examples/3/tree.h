#include <stdbool.h>
#ifndef TREE_H
#define TREE_H 1

struct node {
  struct node *left;
  int value;
  struct node *right;
  bool visited;
};
typedef struct node Tree;

/* A list of nodes in our tree */
typedef struct TreeListCell TreeList;
typedef TreeList NodeList;
struct TreeListCell {
  Tree *head;
  TreeList *tail;
};
typedef struct TreeListCell TreeListCell;

Tree *node(int value, Tree *left, Tree *right);
void tree_free(Tree *tree);

TreeList *cons(Tree *head, TreeList *tail);
TreeList *getNodes(Tree *tree, TreeList *nodes);

#endif
