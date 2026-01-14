#include<stdio.h>

int main () {

    //comparison operators: <, <=, >, >=, == != 
    // will produce 0 or 1 

printf("%d,\n",5>3); //1
printf("%d,\n",5<3); //0
printf("%d,\n",5!=3); //1

//logical operators ! (not)  || (or), &&(and)
printf("%d\n",!(5>3)); //0
printf("%d\n",(5>3)||(10<2));//1
printf("%d\n",(5>3)||!(10<2));//1
printf("%d\n",(5>3)&&(10<2)); //0
printf("%d\n",(5>3)&&!(10<2)); //1
printf("%d\n", 0 && 1); //0

int x = 5==3;
printf("%d\n",x); //0

//demorgan laws
// !(a&&b) = !a || !b
// !(a | b) = !a && !b
printf("%d\n",!(5>3)&&(10<2));// 0
// equivalent to:
printf("%d\n",(!(5>3)||!(10<2)));// 0

/* SELECTION 
IF STATEMENT 
1. SINGLE SITE IF 
2. 

*/






    return 0;
}