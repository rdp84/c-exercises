
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{

    double two_pi = 2.0 * M_PI;
    double h = 0.1;
    double x;

    for (x = 0.0; x < two_pi; x += h) {
     
        double sin_squared = sin(x) * sin(x);
        double cos_squared = cos(x) * cos(x);

        // Using printf("%5.1f: %.15e\n", x, sin(x) * sin(x) + cos(x) * cos(x)) will do the calcualtion wrt to a power of 10
        // It will also introduce an inaccuracy as .15e will use more decimal places than a double is accurate to (when it shifts the decimal point it will bring in a new
        // digit.
        // This is why we sometimes get 9.999999999999999e-1 in the calculation. To fix this you can use .12e.
        // Changing to .15f works because we now use a double to 15 decimal places in our calculation. It is accurate to this point.

        printf("%.15e (%.15f)\n+\n%.15e (%.15f)\n\n", sin_squared, sin_squared, cos_squared, cos_squared);
        printf("%5.1f: %.12e\n", x, sin(x) * sin(x) + cos(x) * cos(x));

    }

    return EXIT_SUCCESS;
}
