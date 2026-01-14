#include<stdio.h>

int main() {

// variables 
double number;
int before;
int after;

printf("Enter a decimal number: ");
scanf("%lf", &number);

// Get the part before the decimal
before = (int) number;

// Get the part after the decimal 

after =(int)((number - before) * 100000);

    printf("The part before the decimal is %d\n", before);
    printf("The part after the decimal is %d\n", after);



    return 0;
}