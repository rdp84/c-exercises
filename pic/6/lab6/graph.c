#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;
Node *node(int value, Node *left, Node *right) {
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}

/* Basic Problems */

int size(Node *node) {
  if (node == empty || node->marked) {
  return 0;
  } else {
    node->marked = true;
    return 1 + size(node->left) + size(node->right);
  }
}

void unmark(Node *node) {
  if (node != empty && node->marked) {
    node->marked = false;
    unmark(node->left);
    unmark(node->right);
  } else {
    return;
  }
}

bool path_from(Node *node1, Node *node2) {
  if (node1 == empty || node2 == empty) {
    return false;
  } else if (node1 == node2) {
    node1->marked = true;
    return true;
  } else if (!node1->marked) {
    node1->marked = true;
    bool path_from_left = path_from(node1->left, node2);
    unmark(node1->left);
    if (path_from_left) {
      bool path_from_right = path_from(node1->right, node2);
      unmark(node1->right);
      return path_from_right;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool cyclic(Node *node) {
  bool path_from_left = path_from(node->left, node);
  unmark(node->left);
  if (path_from_left) {
    return true;
  } else {
    bool path_from_right = path_from(node->right, node);
    unmark(node->right);
    return path_from_right;
  }
}

void get_nodes(Node *node, Node **dest) {
  if (node == empty || node->marked) {
    return;
  } else {
    node->marked = true;
    *dest++ = node;

    get_nodes(node->left, dest);
    get_nodes(node->right, dest);
  }
}

void graph_free(Node *node) {
  int numberOfNodes = size(node);
  Node *dest[numberOfNodes];

  unmark(node);
  get_nodes(node, dest);

  for (--numberOfNodes; numberOfNodes >= 0; numberOfNodes--) {
    free(dest[numberOfNodes]);
  }
}
