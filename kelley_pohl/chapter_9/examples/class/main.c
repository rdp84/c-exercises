
#include "class_info.h"

int main(void)
{
  student tmp, *p = &tmp;

  tmp.grade = 'A';
  tmp.student_id = 910017;
  tmp.last_name = "Casanova";

  printf("tmp.grade = %c\n"
         "tmp.student_id = %d\n"
         "tmp.last_name = %s\n",
         tmp.grade, tmp.student_id, tmp.last_name);

  /*
     last_name is an array of chars so p->last_name will point to first
     elsement of that array
  */

  // derederencing the pointer, so will print 'C'
  printf("(*(p -> last_name)) = %c\n", (*(p -> last_name)));

  // below is equivalent to (*(p -> last_name)) + 1 which is equal to 'C' + 1 = 'D'
  printf("* p -> last_name + 1 = %c\n", * p -> last_name + 1);

  /*
     increment pointer to base address of array by two and dereference -
     will print 'S'
  */
  printf("*(p -> last_name + 2) = %c\n", *(p -> last_name + 2));

  return EXIT_SUCCESS;
}

int fail(student class[])
{
  int i, cnt = 0;

  for (i = 0; i < CLASS_SIZE; ++i)
    cnt += class[i].grade == 'F';

  return cnt;
}
