#include<stdio.h>


// function declarations
#include "functions.h"           // "using quotes" - and not < > - means that the file is in the same directory as the source file
#include "functions.c"         // including the functions.c file here - not a good practice but for simplicity we do it here

int main (){ // main function

    printName(); // function call
    double radius; //   variable declaration
    double area1,area2,area3,totalarea; // variable declaration

radius = getRadius(); // function call

    area1 = calculateArea(radius); // function call

    printf("THE AREA OF THE CIRCLE(radius=%.2lf) IS %.2lf\n", radius,area1); // printing the area
    radius = getRadius(); // function call

    area2 = calculateArea(radius);      // function call

    printf("THE AREA OF THE CIRCLE(radius=%.2lf) IS %.2lf\n", radius,area2); // printing the area

 radius = getRadius(); // function call
    area3 = calculateArea(radius); //   function call

    printf("THE AREA OF THE CIRCLE(radius=%.2lf) IS %.2lf\n", radius,area3); // printing the area

    totalarea = area1+area2+area3; //   calculating the total area

    printf("The total area is %.2lf",totalarea); // printing the total area


    return 0; // end of main function
}

