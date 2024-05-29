#ifndef NODE_H
#define NODE_H 1

struct node {
  unsigned int rc;
  int value;
  struct node *left;
  struct node *right;
};
typedef struct node Node;

const Node *empty = NULL;
Node *node(int value, Node *left, Node *right);
void inc_ref(Node *node);
void dec_ref(Node *node);

#endif
