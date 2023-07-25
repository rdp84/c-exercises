#include <stdio.h>

#define MAXLEN      1000   /* max length of any inpout line */
#define ALLOCSIZE   10000  /* max size of total input */

int get_line(char *, int);
void str_cpy(char *, char *);
int readlines(char[], char *[], int);
