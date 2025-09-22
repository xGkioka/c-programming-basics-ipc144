/* SELECTION 
IF STATEMENT 
1. SINGLE SITE IF 
2. 

*/


#include<stdio.h>

int main () {
// ***************single side if********************* 
  //  int num < 5
// if (num > 0){; 
//printf("num = %d is Possitive\n",num);
//printf("thanks\n");
//}
// printf(" Done \n");

// ****************IF ELSE***********
//int num = -5;
//if (num > 0) 
  //  printf("num = %d is Possitive\n",num);
//else { //if there is more than one statement we need {}
  //  printf("num = %d is Negative\n", num); 
  //  printf("Good\n");
//}
    

//printf(" Done \n");


// ************* Multisides if statements **************

int num = 0;
if (num > 0)
    printf("num = %d is Positive\n",num);
else if (num < 0)
     printf("num = %d is Negative\n",num); 
else 
printf("it is zero\n");

printf("Done\n");
    return 0;

}