#include <stdio.h>

void calculate (int n1, int n2, int* p1, int* p2);


int main () {
int num1 = 2;
int num2 = 5; 


int s, m;
calculate(num1,num2,&s, &m);

printf("sum = %d and mult = %d \n", s, m);


    

    return 0; 
}



void calculate (int n1, int n2, int* p1, int* p2){
    *p1 = n1 + n2;
    *p2 = n1 * n2;



}