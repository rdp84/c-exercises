#include <stdio.h>
#include "alloc.h"

#define MAXLEN  1000 /* max length of any input line */

int  get_line(char *, int);
void str_cpy(char *, char *);
int  readlines(char *[], int);
void writelines(char *[], int);
