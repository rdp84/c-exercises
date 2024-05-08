#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

  tree_free(node1);
}

Tree *node(int value, Tree *left, Tree *right) {
  Tree *t = malloc(sizeof(Tree));
  t->value = value;
  t->visited = false;
  t->left = left;
  t->right = right;
  return t;
}

/* Dynamically allocate a new element of the list */
TreeList *cons(Tree *head, TreeList *tail) {
  TreeList *result = malloc(sizeof(TreeListCell));
  result->head = head;
  result->tail = tail;
  return result;
}

/* Find all nodes in the tree that have not been visited yet */
TreeList *getNodes(Tree *tree, TreeList *nodes) {
  /* Finish if a leaf or a node that has been visited */
  if (tree == NULL || tree->visited) {
    return nodes;
  } else {
    tree->visited = true;
    nodes = cons(tree, nodes);
    nodes = getNodes(tree->right, nodes);
    nodes = getNodes(tree->left, nodes);
    return nodes;
  }
}

void tree_free(Tree *tree) {
  NodeList *nodes = getNodes(tree, NULL);
  while (nodes != NULL) {
    Tree *head = nodes->head;
    NodeList *tail = nodes->tail;
    free(head);
    free(nodes);
    nodes = tail;
  }
}
