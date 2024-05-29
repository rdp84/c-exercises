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
  if (node != NULL) {
    node->rc += 1;
  }
}

void dec_ref(Node *node) {
  if (node != NULL) {
    if (node->rc > 1) {
      node->rc -= 1;
    } else {
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
    /* Still leaks memory, children will end up with rc field of 1 */
    return node(n,
                complete(n-1),  /* bumps rc to 2 */
                complete(n-1)); /* bumps rc to 2 */
  }
}

int main(void) {
  Node *tree = complete(5);
  dec_ref(tree);
  return 0;
}
