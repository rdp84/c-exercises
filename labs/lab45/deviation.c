
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int item_number, input, total;
    double average, deviation = 0.0;

    printf("Please enter the number of integers you wish to calculate the average of: ");
    scanf("%d", &item_number);

    if (item_number < 1) {
        printf("You need to avergae one or more numbers. Please re-run.\n");
        return EXIT_FAILURE;
    }

    int inputs[item_number];
    total = 0;
    int i;

    for (i = 1; i <= item_number; ++i) {
        printf("Please enter your %d number: ", i);
        scanf("%d", &input);
        total += input;
        inputs[i - 1] = input;
    }

    average = (double) total / (double) item_number;
    for (i = 0; i < item_number; ++i)
        deviation += ((inputs[i] - average) * (inputs[i] - average)) / item_number;

    printf("\n\nThe average of the %d number(s) you have entered is: %.2f\n", item_number, average);
    printf("The standard deviation is %.2f\n\n", sqrt(deviation));

    return EXIT_SUCCESS;
}
