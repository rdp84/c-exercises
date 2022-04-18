#include <stdio.h>

int
main(void)
{
  int c, blank, tab, nl;

  blank = tab = nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++blank;
    else if (c == '\t') 
      ++tab;
    else if (c == '\n')
      ++nl;
  }

  printf("blank: %d\n", blank);
  printf("tab: %d\n", tab);
  printf("new line: %d\n", nl);
}
