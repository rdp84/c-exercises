
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int item_number, input, total;
    double average;

    printf("Please enter the number of integrers you wish to calculate the average of: ");
    scanf("%d", &item_number);

    if (item_number < 1) {
        printf("You need to avergae one or more numbers. Please re-run.\n");
        return EXIT_FAILURE;
    }

    total = 0;
    int i;
    for (i = 1; i <= item_number; ++i) {
        printf("Please enter your %d number: ", i);
        scanf("%d", &input);
        total += input;
    }

    average = (double) total / (double) item_number;
    printf("The average of the %d number(s) you have entered is: %.2f\n", item_number, average);

    return EXIT_SUCCESS;
}
