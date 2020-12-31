
#include <stdio.h>
#include <stdlib.h>

/*
  Problem with the code given in the exercise is that it
  declares the structure husband having a member of type
  struct wife but struct wife has not been declared yet.

  A fix would be to declare a type struct spouse and
  then have each husband and wife have a member of
  tyhis type, as below.
*/


struct spouse {
  int  age;
  char name[10];
};

typedef struct spouse spouse;

struct husband {
  int    age;
  char   name[10];
  spouse wife;
};
typedef struct husband husband;

struct wife {
  int    age;
  char   name[10];
  spouse husband;
};
typedef struct wife wife;


int main(void)
{
  spouse aWife = {35, "Lucy"};
  spouse bHusband = {36, "Joe"};

  husband a = {36, "Joe", aWife};
  wife    b = {35, "Lucy", bHusband};
  
  printf("a.age = %d, a.name = %s, a.wife.age = %d " \
         "a.wife.name = %s\n", a.age, a.name,
         a.wife.age, a.wife.name);

  printf("b.age = %d, b.name = %s, b.husband.age = %d " \
         "b.husband.name = %s\n", b.age, b.name,
         b.husband.age, b.husband.name);

  return EXIT_SUCCESS;
}
