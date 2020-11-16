#include "queue.h"

void print_schedule(queue *);

int main(void)
{
  char           processor_id;
  data           process;
  queue          schedule;
  unsigned int   pid;
  unsigned short priority;

  initialize(&schedule);

  /* Read schedule in */
  while ((processor_id = getchar()) != EOF) {
    if (!isspace(processor_id)) {
      assert(scanf("%u %hu", &pid, &priority) == 2);

      process.processor_id = processor_id;
      process.pid = pid;
      process.priority = priority;

      enqueue(process, &schedule);
    }
  }

  /* Sort schedule and print it out */
  sort(&schedule);
  printf("\nSchedule:\n");
  print_schedule(&schedule);

  return EXIT_SUCCESS;
}

void print_schedule(queue *schedule)
{
  data process;
  int  cnt = 0;

  while (!empty(schedule)) {
    process = dequeue(schedule);
    printf("    JOB %u is %u running on processor %c " \
           "with priority %u\n", ++cnt, process.pid,
           process.processor_id, process.priority);
  }
}
