
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int counter, input, total;
    double average;

    printf("Welcome. You will be asked to input integers one at a time. To finish, type a letter or non-digit\n");

    counter = input = total = 0;
    printf("Input the next integer: ");

    while (scanf("%d", &input)) {

        total += input;
        ++counter;
        printf("Input the next integer: ");
    }

    average = (double) total / (double) counter;
    printf("Average of the numbers entered is: %.2f\n", average);

    return EXIT_SUCCESS;
}
