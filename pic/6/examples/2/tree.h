#ifndef TREE_H
#define TREE_H 1

struct node {
  struct node *left;
  int value;
  struct node *right;
};
typedef struct node Tree;

Tree *node(int value, Tree *left, Tree *right);
void tree_free(Tree *tree);

#endif
