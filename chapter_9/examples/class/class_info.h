
#include <stdio.h>
#include <stdlib.h>

#define CLASS_SIZE 100

struct student {
  char *last_name;
  int  student_id;
  char grade;
};
typedef struct student student;


//  Above can also be writeen as:

/*
typedef struct {
  char *last_name;
  int  student_id;
  char grade;
} student;
*/


/* Count the failing grades */
int fail(student []);
