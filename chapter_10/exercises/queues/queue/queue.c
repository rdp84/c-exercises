
#include "queue.h"

void initialize(queue *q)
{
  q->cnt = 0;
  q->front = NULL;
  q->rear = NULL;
}

queue data_to_queue(data d[], int n)
{
  queue q;
  int   i;

  initialize(&q);
  for (i = 0; i < n; ++i)
    enqueue(d[i], &q);

  return q;
}

data *queue_to_data(queue q)
{
  data *data;
  elem *e;
  int  i;

  data = calloc(q.cnt, sizeof(data));
  e = q.front;
  i = 0;

  while (e != NULL) {
    *(data + i) = e->d;
    e = e->next;
    i++;
  }

  return data;
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
