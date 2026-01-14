#include<stdio.h>

// #define PI 3.14 //DEFINING THE 3.14 THE PI AND WE CAN USE THE VAR IN THE CODE AS PI  (USING A MACRO)


int main(){

    double radius, area;
    const double PI = 3.14; // ALSO DEFINE THE PI IN ANOTHER WAY 
    printf("Enter the radius:");
    scanf("%lf",&radius);

    area = radius*radius*PI;

    printf("The area of circle (radius=%.2lf) is %.2lf\n",radius,area);

    return 0;
}