#include "functions.h"          // including the header file for function prototypes and macro
#include<stdio.h>               // including the standard input output library



// function definitions
void printName(void){
    printf("************************\n");
    printf("* Name: Xenofon Gkioka *\n");
    printf("************************\n");
    return;
}

// function definitions
double getRadius(){
    double radius;
     printf("enter the radius\n");
    scanf("%lf",&radius);
    return radius;
}

// function definition
double calculateArea(double radius){
    double area =  PI*radius*radius;
    return area;
}
