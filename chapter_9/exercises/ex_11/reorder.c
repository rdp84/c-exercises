
#include "class.h"

int main(void)
{
  char    grade, surname[SURNAME_LENGTH];
  int     id, i;
  student s, class[CLASS_SIZE];

  for (i = 0;
       scanf("%s", surname) == 1 &&
         scanf("%d", &id) == 1 &&
         scanf(" %c", &grade) == 1 &&
         i < CLASS_SIZE;
       ++i) {

    s.surname = calloc(strlen(surname) + 1,
                       sizeof(char));
    strcpy(s.surname, surname);

    s.id = id;
    s.grade = toupper(grade);

    class[i] = s;
  }

  sort_class(sort_by_grade, class, i);
  sort_class(sort_by_surname, class, i);
  print_class(class, i);
  class_average(class, i);

  return EXIT_SUCCESS;
}

void sort_class(void (*f)(student [], int),
                student class[], int n) {
  f(class, n);
}

void sort_by_grade(student class[], int n) {

  int     i, j;
  student tmp;

  for (i = 0; i < n; ++i)
    for (j = i + 1; j < n; ++j)
      if (class[i].grade > class[j].grade) {
        tmp = class[i];
        class[i] = class[j];
        class[j] = tmp;
      }
}

void sort_by_surname(student class[], int n) {

  int     i, j;
  student tmp;

  for (i = 0; i < n; ++i)
    for (j = i + 1;
         class[i].grade == class[j].grade &&
           j < n;
         ++j)
      if (strcmp(class[i].surname,
                 class[j].surname) > 0) {
        tmp = class[i];
        class[i] = class[j];
        class[j] = tmp;
      }
}

void class_average(student class[], int n) {

  char  grade;
  int   i, gradeCnt;
  float score;

  gradeCnt = 0;
  score = 0.0f;

  for (i = 0; i < n; ++i) {
    grade = class[i].grade;
    gradeCnt += grade;

    if (grade == 'A')
      score += A;
    else if (grade == 'B')
      score += B;
    else if (grade == 'C')
      score += C;
    else if (grade == 'D')
      score += D;
    else if (grade == 'E')
      score += E;
  }

  printf("Average score: %.2f\n", score / n);
  printf("Average grade: %c\n", (char) (gradeCnt / n));
}

void print_class(student class[], int n) {

  int i;

  for (i = 0; i < n; ++i) {
    printf("Name:  %s\n" \
           "Id:    %d\n" \
           "Grade: %c\n\n",
           class[i].surname, class[i].id, class[i].grade);
    free(class[i].surname);
  }
}
