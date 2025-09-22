#include<stdio.h>

int main() {

float celsius;
float fahrenheit;

// Ask for input 
printf("Enter Celcius");
scanf("%f", &celsius);

// Convert Celcius into fahrenheit
fahrenheit = (celsius * 9 / 5) +32;

//Print 
printf("%.2fC is equal to %.2fF\n", celsius, fahrenheit);

    return 0;
}