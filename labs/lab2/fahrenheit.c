
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int fahrenheit;
    double celsius;

    printf("Please input the temperature in Fahrenheith that you'd like to converted to Celsius: ");
    scanf("%d", &fahrenheit);

    celsius = ((double) fahrenheit - 32.0) / 1.8;
    printf("Temperature in Celsius: %.2f\n", celsius);

    return EXIT_SUCCESS;
}
