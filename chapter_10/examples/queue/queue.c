
#include "queue.h"

void initialize(queue *q)
{
  q->cnt = 0;
  q->front = NULL;
  q->rear = NULL;
}

void enqueue(data d, queue *q)
{
  elem *e;
  
  e = malloc(sizeof(elem));
  e->d = d;
  e->next = NULL;

  if (!empty(q)) {
    q->rear->next = e;
    q->rear = e;
  }
  else
    q->front = q->rear = e;

  q->cnt++;
}

data dequeue(queue *q)
{
  data d;
  elem *e;

  d = q->front->d;
  e = q->front;
  
  q->cnt--;
  q->front = q->front->next;
  free(e);

  return d;
}

data front(const queue *q)
{
  return q->front->d;
}

boolean empty(const queue *q)
{
  return ((boolean) q->cnt == EMPTY);
}

boolean full(const queue *q)
{
  return ((boolean) q->cnt == FULL);
}
