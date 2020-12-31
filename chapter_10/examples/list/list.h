
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef  char  DATA;

struct linked_list {
  DATA               d;
  struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT            *LINK;

LINK   string_to_list(char []);
void   print_list(LINK);
int    count(LINK);
void   concatenate(LINK, LINK);
void   insert(LINK, LINK, LINK);
void   delete_list(LINK);
