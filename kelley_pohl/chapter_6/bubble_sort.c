
#include <stdio.h>
#include <stdlib.h>

void bubble(int*, int);
void swap(int*, int*);
void print_array(int*, int);

int main(void)
{
  int a[] = {7, 3, 66, 3, -5, 22, -77, 2};
  bubble(a, 8);
  
  return EXIT_SUCCESS;
}

void bubble(int a[], int n)
{

  int i, j;

  print_array(a, n);
  for(i = 0; i < n; ++i) {
    for(j = n - 1; j > i; --j)
      if (a[j - 1] > a[j])
	//swap(&a[j - 1], &a[j]);
	swap(a + j - 1, a + j);
    print_array(a, n);
  }
}

void swap(int* p, int* q)
{

  int tmp;

  tmp = *p;
  *p = *q;
  *q = tmp;
}

void print_array(int* a, int n)
{

  int i;

  for (i = 0; i < n; ++i)
    printf("%4d", *(a + i));
  printf("\n");
}
