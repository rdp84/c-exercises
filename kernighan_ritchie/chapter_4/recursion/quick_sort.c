#include <stdio.h>
#include <stdlib.h>

void quick_sort(int [], int, int);
void swap(int [], int, int);

int
main(void)
{
  int i, v[] = {8, 2, 1, 4, 3, 6, 7, 5, 9, 10};
  quick_sort(v, 0, 9);

  for (i = 0; i < 10; i++)
    printf("%3d", v[i]);
  putchar('\n');
  
  return EXIT_SUCCESS;
}

/* quick_sort: sort v[left]...v[right] into ascending order */
void
quick_sort(int v[], int left, int right)
{
  int i, last;

  if (left >= right)                   /* do nothing if array contains */
    return;                            /* fewer than two elements */
  swap(v, left, (left + right) / 2);   /* move partition elem */
  last = left;                         /* to v[0] */
  for (i = left + 1; i <= right; i++)  /* partition */
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);                 /* restore partition elem */
  quick_sort(v, left, last - 1);
  quick_sort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void
swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
  
