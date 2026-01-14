/*
Name : Xenofon Gkioka   
student number:
Description: Week 2
*/


#include<stdio.h>
int main() {

    printf("\tWeek 2: \"Variables and expression\"\n");
    int num; //4 bytes
    float age; 
    double salary;
    long num2; // logner bytes
    char ch1; //character 
    // int 3num; error
    // int for; error necause for is being used


    // Assignment Statement
    num = 5;
    salary = 3000.546;
    ch1 = 'c';   // when using ch1 you have to put ' '
    char ch2 = 92;
    // num = 5;
    printf("num = %d\n",num);
    printf("The Salary is %lf\n",salary);
    printf("The Salary is %.2lf\n",salary); //.2 means 2 numbers after the .
    printf("The character is %c\n",ch1); // %c is for characters
     printf("The character is %d\n",ch1); // %d is for characters
     printf("The character is %c\n",ch2);
     printf("The salay is %.2lf and the number is %d\n",salary,num);



     //Expressions
    //Arthmetic operators: + - * / %

    num = 6*4;
    printf("num = %d\n",num);
    num= 6 / 4;
    printf("num = %d\n",num);
    num = 6 % 4;
    printf("num = %d\n",num);
    
    num= num +10;
    printf("num = %d\n",num);

    //compound assignment operators: += -+ *= /= %=

    num+=20; // num = num +10
    printf("num = %d\n",num);
    num%=3; //num = num %3
    printf("num = %d\n",num);

    //increment ++ / decrement --
    num++;
    printf("num = %d\n",num);
    
    printf("num = %d\n",num++);
    printf("num = %d\n",num);


    


    return 0;   //Return the execution to OS
}




/*
1st gcc -Wall ./w2example1.c to create the .exe or .out file
2nd ./a.out
you cant start a var with a digit 
we only have numbers alphabet and _ that we can input
*/
