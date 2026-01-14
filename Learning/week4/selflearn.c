#include<stdio.h>


int main()  { 
int n;
printf("Enter a number: ");
scanf("%d",&n);

if (n % 2 == 0) {
    printf("%d is even\n", n);
} else {
    printf("%d is odd\n", n);   

}

int grade;
printf("Enter your grade(0-100) : ");
scanf("%d",&grade);

if (grade >= 90) {
    printf("Your grade is A\n");
} else if (grade >= 80) {
    printf("Your grade is B\n");
} else if (grade >= 70) {
    printf("Your grade is C\n");
} else if (grade >= 60) {
    printf("Your grade is D\n");
} else {
    printf("Your grade is F\n");
}


int day;
printf("Enter a number (1-7) for the day of the week: ");
scanf("%d",&day);

switch (day) {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    default:
        printf("Invalid input! Please enter a number between 1 and 7.\n");
        break;
}

return 0;
}