#include<stdio.h>   
#define SIZE 5 // defining a constant variable for the size of the array
int getMark();
int main() {
    int mark[SIZE]; // declaring an array to store the marks
    int i;
    int sum=0;
    double average;
    int max = -1000; // assuming marks are non-negative

    for (i = 0; i <SIZE; i++) {
        mark[i] = getMark(); // storing each mark in the array
        sum += mark[i]; // calculating the sum of marks
        if(mark[i] > max) { // finding the maximum mark
            max = mark[i]; // update max if current mark is greater
        }
        
    }
average = (double)sum / 5.0; // calculating the average
printf("The average is: %.2lf\n", average); //  print average
printf("The maximum mark is: %d\n", max);
//print marks
printf("Your marks are: \n");       //print marks
for(i=0;i<SIZE;i++){ //     print marks using a for loop
    printf("Mark[%d] = %d\n", i, mark[i]);  //print marks using a for loop
}
    return 0; 
}

int getMark() {
    int mark;

    printf("Enter your mark: ");
    scanf("%d", &mark);
        while(mark<0 || mark >100){
            printf("\tError: mark must be between 0 and 100 \n");
            printf("Enter your mark:  ");
            scanf("%d", &mark);
        }

    return mark;

}