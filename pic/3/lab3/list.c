#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  int retVal;

  retVal = 0;
  while (list != NULL) {
    retVal += list->head;
    list = list->tail;
  }
  return retVal;
}

void iterate(int (*f)(int), List *list) {
  while (list != NULL) {
    list->head = f(list->head);
    list = list->tail;
  }
}

void print_list(List *list) { 
  printf("[ ");
  while (list != NULL) {
    printf("%d%s", list->head, list->tail == NULL ? " " : ", ");
    list = list->tail;
  }
  printf("]\n");
}

List *merge(List *list1, List *list2) { 
  List *merged = NULL;
  List *tmp;

  while (list1 != NULL && list2 != NULL) {
    if (list1->head >= list2->head) {
      if (merged == NULL) {
        merged = list2;
        list2 = list2->tail;
        merged->tail = NULL;
      }
      else {
        tmp = merged;
        while (tmp->tail != NULL)
          tmp = tmp->tail;
        tmp->tail = list2;
        list2 = list2->tail;
      }
    } else {
      if (merged == NULL) {
        merged = list1;
        list1 = list1->tail;
        merged->tail = NULL;
      }
      else {
        tmp = merged;
        while (tmp->tail != NULL)
          tmp = tmp->tail;
        tmp->tail = list1;
        list1 = list1->tail;
      }
    }
  }
  if (list1 == NULL) {
    tmp = merged;
    while (tmp->tail != NULL)
      tmp = tmp->tail;
    tmp->tail = list2;
  } else {
    tmp = merged;
    while (tmp->tail != NULL)
      tmp = tmp->tail;
    tmp->tail = list1;
  }
  printf("merged list:\n");
  print_list(merged);
  return merged;
}

void split(List *list, List **list1, List **list2) { 
  if (list == NULL) {
    *list1 = NULL;
    *list2 = NULL;
  } else if (list->tail == NULL) {
    *list1 = list;
    *list2 = NULL;
  } else {
    *list1 = list;
    *list2 = list->tail;

    List *tmp;
    while (list != NULL) {
      tmp = list->tail;
      if (tmp != NULL)
        list->tail = list->tail->tail;
      list = tmp;
    }
  }
}


/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *merge_sort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    print_list(list1);
    print_list(list2);
    list1 = merge_sort(list1);
    list2 = merge_sort(list2);
    return merge(list1, list2);
    /* return list; */
  }
}
