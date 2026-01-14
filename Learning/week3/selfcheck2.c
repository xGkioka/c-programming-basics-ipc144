#include<stdio.h>

int sum3Digits(int threeDigitNumber) {
    int sum, digit1, digit2, digit3; // variable declaration
    digit1 = threeDigitNumber / 100; // extracting the first digit
    digit2 = (threeDigitNumber / 10) % 10; // extracting the second digit
    digit3 = threeDigitNumber % 10; // extracting the third digit
    sum = digit1 + digit2 + digit3; // calculating the sum of the digits
    return sum; // returning the sum
}

int main(void) {
    int threeDigitNumber; // variable declaration
    printf("Insert a three digit number: "); // prompt the user for input
    scanf("%d", &threeDigitNumber); // reading the input
    if (threeDigitNumber < 100 || threeDigitNumber > 999) { // checking if the input is a three digit number
        printf("Error: Please enter a valid three digit number.\n"); // error message
        return 1; // exit the program with an error code
    }
    printf("The sum of the digits is: %d\n", sum3Digits(threeDigitNumber)); // function call and printing the result
    return 0; // end of main function
}


/*
int sum3Digits(int threeDigitNumber)
{
	int digit1;
	int digit2;
	int digit3;

	//left most digit.. example 923/100 = 9
	digit1 = threeDigitNumber/100;
	//middle digit... example 923/10 = 92.  92%10 = 2
	digit2 = (threeDigitNumber/10) % 10;
	//last digit ... example 923%10 = 3
	digit3 = threeDigitNumber%10;
	return digit1 + digit2 + digit3;
}
*/