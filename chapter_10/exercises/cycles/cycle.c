
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct linked_list {
  DATA               d;
  struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT            *LINK;

LINK string_to_list(char []);
void prn_list(LINK);

LINK concatenate(LINK, LINK);
LINK concatenate_iter(LINK, LINK);
LINK copy_cat(LINK, LINK);

LINK insert_head(DATA, LINK);
LINK insert_tail(DATA, LINK);
LINK insert_following(DATA, DATA, LINK);
LINK insert_at(DATA, int, LINK);

int  iscycle(LINK);
void delete_list(LINK);

int main(void)
{
  LINK a, b, c, f;

  a = string_to_list("ABC");
  b = string_to_list("DEF");
  f = string_to_list("XY");
  f->next->next = a->next;

  c = concatenate(a, f);
  /* c = copy_cat(a, b); */
  /* c = concatenate_iter(a, b); */
  prn_list(a);
  prn_list(b);
  prn_list(c);

  a = insert_head('Z', a);
  a = insert_tail('Y', a);
  a = insert_following('G', 'F', a);
  prn_list(a);

  LINK d = insert_tail('D', NULL);
  prn_list(d);

  LINK e = insert_following('E', 'D', NULL);
  e = insert_at('D', 0, e);
  e = insert_at('F', 3, e);
  prn_list(e);

  delete_list(a);
  delete_list(d);
  delete_list(e);
  /*
  delete_list(b);
  delete_list(c);
  */
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
    return head;
  }
}

void prn_list(LINK head)
{
  if (head == NULL)
    printf("NULL\n");
  else {
    printf("< %c > --> ", head->d);
    prn_list(head->next);
  }
}

LINK concatenate(LINK a, LINK b)
{
  if (a == NULL)
    a = b;
  else {
    LINK bHead = b;

    while (b != NULL) {
      if (a == b) {
        printf("WARNING: concatenation of lists will result in a cycle\n");
        return a;
      }
      b = b->next;
    }
    a->next = concatenate(a->next, bHead);
  }

  return a;
}

LINK copy_cat(LINK a, LINK b)
{
  LINK head = NULL, tail;

  if (a != NULL) {
    head = malloc(sizeof(ELEMENT));
    head->d = a->d;
    tail = head;

    a = a->next;
    while (a != NULL) {
      tail->next = malloc(sizeof(ELEMENT));
      tail = tail->next;
      tail->d = a->d;

      a = a->next;
    }
  }

  if (b != NULL) {
    if (head == NULL) {
      head = malloc(sizeof(ELEMENT));
      head->d = b->d;
      tail = head;
    }
    else {
      tail->next = malloc(sizeof(ELEMENT));
      tail = tail->next;
      tail->d = b->d;
    }

    b = b->next;
    while (b != NULL) {
      tail->next = malloc(sizeof(ELEMENT));
      tail = tail->next;
      tail->d = b->d;

      b = b->next;
    }
  }

  return head;
}

LINK concatenate_iter(LINK a, LINK b)
{
  if (a == NULL)
    return b;

  LINK aHead, bHead;
  aHead = a;
  bHead = b;

  while (a->next != NULL) {
    while (b != NULL) {
      if (a == b) {
        printf("WARNING: concatenation of lists will result in a cycle\n");
        return aHead;
      }
      else
        b = b->next;
    }
    a = a->next;
    b = bHead;
  }
  a->next = bHead;
  return aHead;
}

int iscycle(LINK head)
{
  LINK initial;

  if (head == NULL || head->next == NULL)
    return 0;

  initial = head;
  head = head->next;

  while (head != NULL) {
    if (head == initial)
      return 1;
    head = head->next;
  }
  return 0;
}

LINK insert_head(DATA d, LINK l)
{
  LINK head = malloc(sizeof(ELEMENT));
  head->d = d;
  head->next = l;

  return head;
}

LINK insert_tail(DATA d, LINK l)
{
  if (l == NULL) {
    LINK tail = malloc(sizeof(ELEMENT));
    tail->d = d;
    tail->next = NULL;

    l = tail;
  }
  else
    l->next = insert_tail(d, l->next);

  return l;
}

LINK insert_following(DATA d, DATA following, LINK head)
{
  if (head == NULL ||
      head->d == following) {

    LINK insert = malloc(sizeof(ELEMENT));
    insert->d = d;

    if (head != NULL) {
      insert->next = head->next;
      head->next = insert;
    }
    else
      head = insert;
  }
  else
    head->next = insert_following(d, following, head->next);

  return head;
}

LINK insert_at(DATA d, int index, LINK head)
{
  if (index == 0 || head == NULL) {
    LINK insert = malloc(sizeof(ELEMENT));
    insert->d = d;

    if (head != NULL) {
      insert->next = head;
      head = insert;
    }
    else
      head = insert;
  }
  else
    head->next = insert_at(d, --index, head->next);

  return head;
}

void delete_list(LINK head)
{
  if (head != NULL) {
    delete_list(head->next);
    free(head);
  }
}
