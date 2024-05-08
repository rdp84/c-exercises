#ifndef TREE_H
#define TREE_H 1

struct node {
  int value;
  struct node *left;
  struct node *right;
};
typedef struct node Tree;

struct arena {
  int size;
  int current;
  Tree *elts;
};
typedef struct arena arena;
typedef struct arena *arena_t;

arena_t make_arena(int size);
void free_arena(arena_t arena);

Tree *node(int value, Tree *left, Tree *right, arena_t arena);
#endif
