#include <stdio.h>
#include <stdlib.h>

/*
 * All sizes except the first need to be specified
 *
 * Sotage mapping function here is specified by noting that
 *
 * a[i][j][k] is equivalent to *(&a[0][0][0] + 2*3*i + 3*j + k)
 */
int sum(int a[][2][3]);

int
main(void)
{
  int total, a[][2][3] = {
    {{1, 2, 3}, {4, 5, 6}},
    {{7, 8, 9}, {10, 11, 12 }}
  };

  total = sum(a);
  printf("sum of a: %d\n", total);

  return EXIT_SUCCESS;
}

int
sum(int a[][2][3])
{
  int i, j, k, sum = 0;

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      for (k = 0; k < 3; k++)
        sum += a[i][j][k];

  return sum;
}
