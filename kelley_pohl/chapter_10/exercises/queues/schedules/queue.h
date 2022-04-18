/* A linked list implementation of a queue */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL  1000

typedef enum {false, true} boolean;

struct data {
  char           processor_id;
  unsigned int   pid;
  unsigned short priority;
};

typedef struct data data;

/* An element in the queue */
struct elem {
  data        d;
  struct elem *next;
};

typedef struct elem  elem;

struct queue {
  int  cnt;
  elem *front;
  elem *rear;
};

typedef struct queue queue;

void    initialize(queue *);
queue   data_to_queue(data [], int);
data    *queue_to_data(queue);
void    enqueue(data, queue *);
data    dequeue(queue *);
data    front(const queue *);
boolean empty(const queue *);
boolean full(const queue *);
void    sort(queue *);
void    swap(elem *, elem *);
