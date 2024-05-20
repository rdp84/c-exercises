#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *node(int value, Node *left, Node *right) {
  Node *retValue = malloc(sizeof(Node));
  retValue->rc = 1;
  retValue->value = value;

  retValue->left = left;
  inc_ref(left);

  retValue->right = right;
  inc_ref(right);

  return retValue;
}

void inc_ref(Node *node) {
  if (node != NULL)
    node->rc += 1;
}

void dec_ref(Node *node) {
  if (node != NULL) {
    if (node->rc > 1)
      node->rc -= 1;
    else {
      dec_ref(node->left);
      dec_ref(node->right);
      free(node);
    }
  }
}

Node *complete(int n) {
  if (n == 0) {
    return empty;
  } else {
    Node *sub = complete(n-1);
    Node *result = node(n, sub, sub);
    /*
      If you were to forget to decrement here you'd have a memory leak
      as the children would have a rc field of 1
     */
    dec_ref(sub);
    return result;
  }
}

int main(void) {
  Node *tree = complete(5);
  dec_ref(tree);
  return 0;
}
