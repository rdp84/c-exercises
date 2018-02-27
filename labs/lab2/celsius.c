
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int celsius;
    double fahrenheit;

    printf("Please input the temperature in Celsius that you'd like to be converted to Fahrenheit: ");
    scanf("%d", &celsius);

    fahrenheit = ((double) celsius * 1.8) + 32;
    printf("Temperature in Fahrenheit: %.3f\n", fahrenheit);

    return EXIT_SUCCESS;
}
