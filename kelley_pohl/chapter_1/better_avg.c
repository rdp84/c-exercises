
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int     i;
    double  x;
    double avg = 0.0; // a better average
    double navg;      // a naive average
    double sum = 0.0;

    if (scanf("%lf", &x) != 1) {
        printf("No data - bye!");
        exit(1);
    }

    avg = navg = sum = x;
    
    printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n",
           "Count", "Item", "Average", "Naive Average",
           "-----", "----", "-------", "-------------");

    printf("%5d%17e%17e%17e\n", 1, x, avg, navg);
    
    for(i = 2; scanf("%lf", &x) == 1; ++i) {

      avg += (x - avg) / i;
      sum += x;
      navg = sum / i;
      printf("%5d%17e%17e%17e\n", i, x, avg, navg);
    }
    return 0;
}
