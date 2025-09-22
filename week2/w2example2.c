#include<stdio.h>

int main(){
    //1 declare the variables

    int num1, num2, sum;
    
    // assign values to num1 and num2

    // num1 = 7;
    printf("Enter num1: "); // addint text to input the num
    scanf("%d",&num1); //this is for inputing numbers


    // num2 = 10;
    printf("Enter num1: ");
     scanf("%d",&num2); //this is for inputing numbers

    //find the sum of num1 and num 2

    sum = num1 + num2;

    printf("the sum of %d and %d is = %d\n",num1,num2,sum); 

    return 0;
}