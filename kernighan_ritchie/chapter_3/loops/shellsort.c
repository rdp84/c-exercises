#include <stdio.h>
#include <stdlib.h>

void shellsort(int v[], int n);

int
main(void)
{
  int i, v[] = {5, 2, -1, 12, 11, 22};
  for (i = 0; i < 6; ++i)
    printf("%d ", v[i]);
  putchar('\n');
  
  shellsort(v, 6);
  for (i = 0; i < 6; ++i)
    printf("%d ", v[i]);
  putchar('\n');
  
  return EXIT_SUCCESS;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void
shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
  }
}
