
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct dllist {
  DATA          d;
  struct dllist *prev;
  struct dllist *next;
};

typedef struct dllist ELEMENT;
typedef ELEMENT       *LINK;

LINK string_to_list(char []);
void prn_list_next(LINK);
void prn_list_prev(LINK);
void delete_list(LINK);

LINK insert_head(DATA, LINK);
void insert_tail(DATA, LINK);
void insert(LINK, LINK, LINK);

LINK delete_head(LINK);
void delete_tail(LINK);
void delete(LINK);
void delete_dupl(LINK);

int main(void)
{
  LINK p1, q;

  p1 = string_to_list("CD");
  q = string_to_list("B");

  p1 = insert_head('A', p1);
  insert(p1, p1->next, q);
  insert_tail('E', p1);
  delete(p1->next->next);
  insert_tail('B', p1);

  prn_list_next(p1);
  prn_list_prev(p1);

  delete_dupl(p1);

  prn_list_next(p1);
  prn_list_prev(p1);

  delete_list(p1);

  return EXIT_SUCCESS;
}

LINK string_to_list(char str[])
{
  LINK head;

  if (str[0] == '\0')
    return NULL;
  else {
    head = malloc(sizeof(ELEMENT));
    head->d = str[0];
    head->next = string_to_list(str + 1);

    if (head->next != NULL)
      head->next->prev = head;

    return head;
  }
}

void prn_list_next(LINK head)
{
  if (head == NULL)
    printf("NULL\n");
  else {
    printf("< %c > --> ", head->d);
    prn_list_next(head->next);
  }
}

void prn_list_prev(LINK head)
{
  if (head == NULL)
    printf("NULL\n");
  else {
    if (head->next == NULL)
      printf("< %c > --> ", head->d);
    else
      prn_list_prev(head->next);

    if (head->prev == NULL)
      printf("NULL\n");
    else
      printf("< %c > --> ", head->prev->d);
  }
}

LINK insert_head(DATA d, LINK l)
{
  LINK head = calloc(1, sizeof(ELEMENT));
  head->d = d;
  head->next = l;
  l->prev = head;

  return head;
}

void insert_tail(DATA d, LINK l)
{
  while (l->next != NULL)
    l = l->next;

  LINK tail = calloc(1, sizeof(ELEMENT));
  tail->d = d;
  l->next = tail;
  tail->prev = l;
}

void insert(LINK p1, LINK p2, LINK q)
{
  assert(p1->next == p2);

  p1->next = q;
  q->prev = p1;
  q->next = p2;
  p2->prev = q;
}

LINK delete_head(LINK l)
{
  assert(l->prev == NULL);
  LINK tmp = NULL;

  if (l->next != NULL) {
    l->next->prev = NULL;
    tmp = l->next;
  }

  free(l);
  return tmp;
}

void delete_tail(LINK l)
{
  while (l->next != NULL)
    l = l->next;

  if (l->prev != NULL)
    l->prev->next = NULL;

  free(l);
}

void delete(LINK l)
{
  l->prev->next = l->next;
  l->next->prev = l->prev;

  free(l);
}

void delete_dupl(LINK head)
{
  LINK tmp;
  for (; head != NULL; head = head->next) {
    for (tmp = head->next; tmp != NULL; tmp = tmp->next) {
      if (head->d == tmp->d) {
        tmp->prev->next = tmp->next;
        if (tmp->next != NULL)
          tmp->next->prev = tmp->prev;
        free(tmp);
      }
    }
  }
}

void delete_list(LINK head)
{
  if (head != NULL) {
    LINK next = head->next;
    free(head);
    delete_list(next);
  }
}
