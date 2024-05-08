#include <stdlib.h>
#include "tree.h"

Tree *empty = NULL;

int tree_member(int x, Tree *tree) { 
  if (tree == empty) 
    return 0;
  else if (x == tree->value) 
    return 1;
  else if (x < tree->value) 
    return tree_member(x, tree->left);
  else 
    return tree_member(x, tree->right);
}

Tree *tree_insert(int x, Tree *tree) { 
  if (tree == empty) {
    Tree *insert = (Tree *) malloc(sizeof(Tree));
    insert->value = x;
    insert->left = empty;
    insert->right = empty;

    return insert;
  }
  else if (x < tree->value)
    tree->left = tree_insert(x, tree->left);
  else if (x > tree->value)
      tree->right = tree_insert(x, tree->right);

  return tree;
}

void tree_free(Tree *tree) { 
  if (tree->left != empty)
    tree_free(tree->left);

  if (tree->right != empty)
    tree_free(tree->right);

  free(tree);
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
  if (tree->left == empty) {
    if (*new_tree == tree)
      *new_tree = tree->right;
    else
      (*new_tree)->left = tree->right;
    *min = tree->value;

    free(tree);
  }
  else
    pop_minimum(tree->left, min, &tree);

}

Tree *tree_remove(int x, Tree *tree) { 
  Tree *retVal = tree;
  Tree *parent = empty;

  while ((tree != empty) && (tree->value != x)) {
    parent = tree;
    tree = x < tree->value ? tree->left : tree->right;
  }

  if (tree == empty)
    return retVal;
    
  if (tree->right == empty) {
    if (tree->left == empty) {
      if (parent == empty)
        retVal = empty;
      else if (parent->left == tree)
        parent->left = empty;
      else
        parent->right = empty;

      free(tree);
    } else {
      pop_minimum(tree->left, &x, &(tree->left));
      tree->value = x;
    }
  } else {
      pop_minimum(tree->right, &x, &(tree->right));
      tree->value = x;
  }
  return retVal;
}

