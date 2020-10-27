
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLASS_SIZE     100
#define SURNAME_LENGTH 20

#define A 5
#define B 4
#define C 3
#define D 2
#define E 1
#define F 0

typedef struct {
  char *surname;
  int   id;
  char  grade;
} student;

void sort_class(void (*f)(student [], int),
                student [], int);
void sort_by_grade(student [], int);
void sort_by_surname(student [], int);
void class_average(student [], int);
void print_class(student [], int);
