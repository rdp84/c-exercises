
#include <stdio.h>
#include <stdlib.h>


int main(void)
{

    int first, second;
    double average;

    printf("Please enter a number: ");
    scanf("%d", &first);

    printf("Please enter a second number: ");
    scanf("%d", &second);

    average = ((double) first + (double) second) / 2.0;
    printf("The average of %d and %d is: %.2f\n", first, second, average);

    return EXIT_SUCCESS;
}
