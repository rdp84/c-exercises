#include <stdio.h>

#define MAXLEN     1000   /* max length of any input line */
#define ALLOCSIZE  10000

int  get_line(char *, int);
void str_cpy(char *, char *);
int  readlines(char[], char *[], int);
void writelines(char *[], int);
