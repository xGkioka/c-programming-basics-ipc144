#include<stdio.h>   
#define SIZE 5 // defining a constant variable for the size of the array
int getMark();
void printMarks(int marks[], int used); // function prototype to print marks
int sumMarks(int marks[], int used); // function prototype to sum marks
int maxMark(int marks[], int used); // function prototype to find maximum mark
int main() {
    int mark[SIZE]; // declaring an array to store the marks
    int i;
    int sum=0;
    double average;
    int max = -1000; // assuming marks are non-negative

 /*  for (i = 0; i <SIZE; i++) {
        mark[i] = getMark(); // storing each mark in the array
        sum += mark[i]; // calculating the sum of marks
        if(mark[i] > max) { // finding the maximum mark
            max = mark[i]; // update max if current mark is greater
        }
       
    }  */ 
sum = sumMarks(mark, SIZE); // calling function to sum marks
max = maxMark(mark, SIZE); // calling function to find maximum mark

average = (double)sum / 5.0; // calculating the average
printf("The average is: %.2lf\n", average); //  print average
printf("The maximum mark is: %d\n", max);

printMarks(mark, SIZE); // calling function to print all marks

    return 0; 
}

int getMark() {
    int mark;

    printf("Enter your mark: ");
    scanf("%d", &mark);
        while(mark<0 || mark >100){ // input validation
            printf("\tError: mark must be between 0 and 100 \n");
            printf("Enter your mark:  ");
            scanf("%d", &mark);
        }

    return mark;

}

void printMarks(int marks[], int used) {
    printf("The marks are:\n"); // print header
    for(int i = 0; i < used; i++) {
        printf("Mark %d: %d\n", i + 1, marks[i]);
    }
}


int sumMarks(int marks[], int used) {
    int sum = 0; // initialize sum to 0
    for(int i = 0; i < used; i++) {
        sum += marks[i];
    }
    return sum;
}


int maxMark(int marks[], int used) {
    int max = marks[0]; // assuming marks are non-negative
    for(int i = 1; i < used; i++) {
        if(marks[i] > max) {
            max = marks[i];
        }
    }
    return max;
} 