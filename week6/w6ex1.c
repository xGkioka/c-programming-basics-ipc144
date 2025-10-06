#include<stdio.h>   

int getMark();
int main() {
    int mark;
    int i;
    int sum=0;
    double average;


    for (i = 0; i < 5; i++) {
        mark = getMark();
        sum += mark;
    }
average = (double)sum / 5.0;
printf("The average is: %.2lf\n", average);

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