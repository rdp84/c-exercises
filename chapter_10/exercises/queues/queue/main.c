#include "queue.h"

void add_pid_to_schedule(queue *);
void print_schedule(queue *);

int main(void)
{
  data  tmp, pid, d1[6] = {1, 2, 3, 4, 5, 76}, *d2; 
  queue q, a, b, c, d;;
  int   i;

  q = data_to_queue(d1, 6);
  d2 = queue_to_data(q);

  printf("data_to_queue returned the following:\n");
  while (!empty(&q)) {
    tmp = dequeue(&q);
    printf("%u --> ", tmp);
  }
  printf("NULL\n");

  printf("\nqueue_to_data returned the following:\n");
  for (i = 0; i < 6; ++i)
    printf("d2[%d] = %u\n", i, *(d2 + i));
  free(d2);

  /* Initialize a load of schedules */
  initialize(&a);
  initialize(&b);
  initialize(&c);
  initialize(&d);

  /* Read schedule in */
  while ((i = getchar()) != EOF) {
    switch(i) {
    case 'A':
      add_pid_to_schedule(&a);
      break;
    case 'B':
      add_pid_to_schedule(&b);
      break;
    case 'C':
      add_pid_to_schedule(&c);
      break;
    case 'D':
      add_pid_to_schedule(&d);
    }
  }  

  /* Print out the schedules */
  printf("\nA's schedule:\n");
  print_schedule(&a);

  printf("\nB's schedule:\n");
  print_schedule(&b);

  printf("\nC's schedule:\n");
  print_schedule(&c);

  printf("\nD's schedule:\n");
  print_schedule(&d);

  return EXIT_SUCCESS;
}

void add_pid_to_schedule(queue *sched)
{
  data pid;
  assert(scanf("%u", &pid) == 1);
  if (!full(sched))
    enqueue(pid, sched);
}

void print_schedule(queue *sched)
{
  data pid;
  int  cnt = 0;

  while (!empty(sched)) {
    pid = dequeue(sched);
    printf("    JOB %u is %u\n", ++cnt, pid);
  }
}
