#include <stdio.h>

// prototype (just a “heads-up” for the compiler)
double metricHeight(int feet, int inches);

int main(void) {
    int feet, inches; 

    printf("Insert your height in feet: ");
    scanf("%d", &feet);

    printf("Insert your height in inches: ");
    scanf("%d", &inches);

    // call the function
    printf("Your height in metric is %.2lf cm\n", metricHeight(feet, inches));

    return 0;
}

// definition (actual code lives down here)
double metricHeight(int feet, int inches) {
    return (feet * 30.48) + (inches * 2.54);
}
