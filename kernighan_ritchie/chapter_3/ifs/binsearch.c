#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int binsearch_two_tests(int x, int v[], int n);
int binsearch_one_test(int x, int v[], int n);

int
main(void)
{
  int result, v[SIZE] = { -2, 0, 11, 25, 101 };

  result = binsearch_two_tests(-2, v, SIZE);
  printf("binsearch_two_tests: %d\n", result);

  result = binsearch_one_test(-2, v, SIZE);
  printf("binsearch_one_test: %d\n", result);

  return EXIT_SUCCESS;
}

/* binsearch_two_tests: find x in v[0] <= v[1] <= v[2] ... <= v[n-1] 
   Uses two tests in the loop, possibly less efficient
*/
int
binsearch_two_tests(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else                    /* found match */
      return mid;
  }

  return -1; /* no match */
}

/* binsearch_one_test: find x in v[0] <= v[1] <= v[2] ... <= v[n-1] 
   Uses one test in the loop
*/
int
binsearch_one_test(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high && x != v[mid]) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  if (x == v[mid])
    return mid;
  else
    return -1;
}
