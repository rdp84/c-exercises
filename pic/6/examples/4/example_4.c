#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
  arena_t arena = make_arena(2);

  Tree *node1 = node(0, NULL, NULL, arena);
  /* Its a DAG now */
  Tree *node2 = node(1, node1, node1, arena);

  printf("Tree * has size: %lu\n", sizeof(Tree *));
  printf("int has size: %lu\n", sizeof(int));
  printf("struct node has size: %lu\n", sizeof(Tree));

  printf("node1 has address %p\n", node1);
  printf("node2 has address %p\n", node2);

  free(arena);
  
  return 0;
}

arena_t make_arena(int size) {
  arena_t arena = malloc(sizeof(arena));
  arena->size = size;
  arena->current = 0;
  arena->elts = malloc(size * sizeof(Tree));
  return arena;
}

Tree *node(int value, Tree *left, Tree *right, arena_t arena) {
  if (arena->current < arena->size) {
    /* Initialize current element */
    Tree *t = arena->elts + arena->current;
    /* Increment current */
    arena->current += 1;

    /* Initialize and return node */
    t->value = value;
    t->left = left;
    t->right = right;

    return t;
  } else {
    return NULL;
  }
}

void free_arena(arena_t arena) {
  /* All tree nodes allocated from the arena are freed at once */
  free(arena->elts);
  /* Free whole arena at the same time */
  free(arena);
}
