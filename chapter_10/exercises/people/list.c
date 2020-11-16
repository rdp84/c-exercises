
#include "list.h"

/*
   List creation, transforming an array into a list
   recursively
*/
LINK create_l(DATA d[], int n) {

  LINK head;

  if (n == 0)     /* Base case */
    return NULL;
  else {
    head = malloc(sizeof(ELEMENT)); /*allocate storage*/
    head->d = d[n - 1];
    head->next = create_l(d, --n);
    return head;
  }
}

/* Recursive deletion of a list */
void delete_list(LINK head)
{
  if (head != NULL) {
    delete_list(head->next);
    free(head);              /* release storage */
  }
}

/* Print a list recursively */
void print_list(LINK head)
{
  if (head == NULL)
    printf("NULL\n");
  else {
    printf("< name: %s, age: %d, weight: %d > --> ",
           head->d.name, head->d.age, head->d.weight);
    print_list(head->next);
  }
}

/* Count a list recursively */
int count(LINK head)
{
  if (head == NULL)
    return 0;
  else
    return (1 + count(head->next));
}

/*
   Count the number of people above a given weight
   and age
 */
int count_weight_age(LINK head, int weight, int age)
{
  int cnt = 0;

  while (head != NULL) {
    if (head->d.weight > weight &&
        head->d.age > age)
      ++cnt;
    head = head->next;
  }

  return cnt;
}

/* Concatenate list a and b with a as head */
void concatenate(LINK a, LINK b)
{
  assert(a != NULL);
  if (a->next == NULL)
    a->next = b;
  else
    concatenate(a->next, b);
}

/* Inserting an element in a linked list */
void insert(LINK p1, LINK p2, LINK q)
{
  assert(p1->next == p2);
  p1->next = q;
  q->next = p2;
}

/* Compare two people by either age or name */
int compare(DATA *d1, DATA *d2, compare_by c)
{
  return c == age ?
    d1->age > d2->age :
    strcmp(d1->name, d2->name) > 0;
}

/*
   Sort a list of people based on a comparison field
   and by a comparison function
*/
void sort(LINK head, compare_by c,
          int (*f)(DATA *, DATA *, compare_by))
{
  LINK n;

  if (head == NULL ||
      head->next == NULL)
    return;

  for (; head != NULL; head = head->next)
    for (n = head->next; n != NULL; n = n->next)
      if ((*f)(&(head->d), &(n->d), c))
        swap(head, n);
}

/* Sort a list of people by age */
void sort_age(LINK head)
{
  sort(head, age, compare);
}

/* Sort a list of people by name */
void sort_name(LINK head)
{
  sort(head, name, compare);
}

/* Swap the index/position of two people in a list */
void swap(LINK p1, LINK p2)
{
  DATA tmp;

  tmp = p1->d;
  p1->d = p2->d;
  p2->d = tmp;
}
