
#include "tree.h";

/* Inorder binary tree traversal */
void inorder(BTREE root)
{
  if (root != NULL) {
    inorder(root->left);    /* recur left */
    printf("%c ", root->d);
    inorder(root->right);   /* recur right */
  }
}

void preorder(BTREE root)
{
  if (root != NULL) {
    printf("%c ", root->d);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(BTREE root)
{
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->d);
  }
}

BTREE new_node(void)
{
  return malloc(sizeof(NODE));
}

BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
  BTREE t;

  t = new_node();
  t->d = d1;
  t->left = p1;
  t->right = p2;

  return t;
}

BTREE create_tree(DATA a[], int i, int size)
{
  if (i >= size)
    return NULL;
  else
    return (init_node(a[i],
                      create_tree(a, 2 * i + 1, size),
                      create_tree(a, 2 * i + 2, size));
}
