#include <stdio.h>
#include <stdlib.h>

/*
 * In multi-dimensional arrays, elements are stored contiguously one after the
 * the other in memory. It is usually convenient though to think of a two-dimensional
 * array as rectangualr collection of elements with rows and columns.
 *
 * For any array, the mapping between pointer values and array indices is called the
 * storage mapping function. Consider the decalaration
 *
 * int a[3][5];
 *
 * then the storage mapping function is specified by noting that
 * a[i][j] is equivalent to *(&a[0][0] + 5*i + j)
 */

/*
 * With two-dimensional arrays you need to specify the number of columns
 * in the header of any function definitions that have a two-dimensional
 * array as a parameter. This is so the compiler can determine the
 * correct storage mapping function, generating object code that accesses
 * the correct element in memory.
 */
int sum(int [][3]);

int
main(void)
{
  int total, a[2][3] = {{1, 2, 3}, {4, 5, 6}};

  total = sum(a);
  
  printf("sum of a: %d\n", total);

  return EXIT_SUCCESS;
}

int
sum(int a[][3])
{
  int i, j, sum = 0;

  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      sum += a[i][j];

  return sum;
}
