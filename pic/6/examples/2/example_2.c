#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main(void) {
  /* Construct a Directed Acyclic Graph (DAG) */
  Tree *node2 = node(2, NULL, NULL);
  /* node1 has two pointers to node2 */
  Tree *node1 = node(1, node2, node2);

  printf("node1 value: %d\n", node1->value);
  printf("node2 value: %d\n", node2->value);

  printf("node1 address: %p\n", node1);
  printf("node2 address: %p\n", node2);
  printf("node1->left address: %p\n", node1->left);
  printf("node1->right address: %p\n", node1->right);

  /* node2 will be freed twice which leads to a segmentation fault */
  /* tree_free(node1); */
}

Tree *node(int value, Tree *left, Tree *right) {
  Tree *t = malloc(sizeof(Tree));
  t->value = value;
  t->left = left;
  t->right = right;
  return t;
}

void tree_free(Tree *tree) {
  if (tree != NULL) {
    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
  }
}
