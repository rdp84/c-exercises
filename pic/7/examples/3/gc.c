#include "gc.h"

Alloc *make_allocator(void) {
  Alloc *a = malloc(sizeof(Alloc));
  a->roots = NULL;
  a->nodes = NULL;

  return a;
}

Node *node(int value, Node *left, Node *right, Alloc *a) {
  Node *r = malloc(sizeof(Node));
  r->value = value;
  r->left = left;
  r->right = right;

  r->mark = false;
  r->next = a->nodes;
  a->nodes = r;
  
  return r;
}

Root *root(Node *node, Alloc *a) {
  Root *g = malloc(sizeof(Root));
  g->start = node;
  g->next = a->roots;
  a->roots = g;

  return g;
}

void mark_node(Node *node) {
  if (node != NULL && !node->mark) {
    node->mark = true;
    mark_node(node->left);
    mark_node(node->right);
  }
}

void mark(Alloc *a) {
  Root *g = a->roots;
  while(g != NULL) {
    mark_node(g->start);
    g = g->next;
  }
}

void sweep(Alloc *a) {
  Node *n = a->nodes;
  Node *live = NULL;

  while (n != NULL) {
    Node *t1 = n->next;
    if (!(n->mark)) {
      free(n);
    } else {
      n->mark = false;
      n->next = live;
      live = n;
    }
    n = t1;
  }
  a->nodes = live;
}

void gc(Alloc *a) {
  mark(a);
  sweep(a);
}
