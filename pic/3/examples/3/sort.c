#include "example_3.h"

void
sort(int a[], const int len, int (cmp)(int, int))
{
  int i, j, tmp;

  for (i = 0; i < len-1; i++)
    for (j = 0; j < len-1-i; j++)
      if ((cmp)(a[j], a[j+1])) {
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
}
