#define MAXLINES  5000  /* max #lines to be sorted */

extern char *lineptr[];

void swap(char *[], int, int);
int  str_cmp(char *, char *);
void qsort(char *[], int, int);
