
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array(int *, int);
int sum_array(int *, int);
void wrt_array(int *, int);

int main(void)
{
  int *a, n;

  srand(time(NULL));
  printf("\n%s\n",
	 "This program does the following repeatedly:\n"
	 "\n"
	 " 1 - create space for an array of size of n\n"
	 " 2 - fill the array with randomly distributed digits\n"
	 " 3 - print the array and the sum of its elements\n"
	 " 4 - release the space\n");

  for( ; ;) {
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n < 1)
      break;
    putchar('\n');
    a = calloc(n, sizeof(int));
    fill_array(a, n);
    wrt_array(a, n);
    printf("sum = %d\n\n", sum_array(a, n));
    free(a);
  }

  printf("\nBye!\n\n");
  return EXIT_SUCCESS;
}

void fill_array(int *a, int n)
{
  int i;

  for (i = 0; i < n; ++i)
    *(a + i) = rand() % 19 - 9;
}

int sum_array(int *a, int n)
{
  int i, sum = 0;

  for (i = 0; i < n; ++i)
    sum += *(a + i);
  return sum;
}

void wrt_array(int *a, int n)
{
  int i;

  printf("a = [");
  for (i = 0; i < n; ++i)
    printf("%d%s", *(a + i), ((i < n - 1) ? ", " : "]\n") );
}
