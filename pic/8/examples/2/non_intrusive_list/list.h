#ifndef LIST_H
#define LIST_H

struct List {
  void *data;
  struct List *tail;
};
typedef struct List List;
typedef List* List_t;

List_t cons_list(void *, List_t);
void print_list(List_t);

#endif
