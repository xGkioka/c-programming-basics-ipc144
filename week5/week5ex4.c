#include <stdio.h>
int getNumStarts(){
    int num;
    printf("Enter number of start\n");
    scanf("%d", &num);
    while(num<1 || num>10){ //condition of invalid number 
        printf("Invalid number, Enter number of start between 1 and 10\n");
        scanf("%d", &num);
    }
    return num; 
}
   void drawline(int n){ 
    int i;
    for(int i=0; i<n; i++){
        printf("*");
    }
   printf("\n");

   }
int main(){

int numStart;
numStart = getNumStarts();
drawline(numStart);
    return 0;
}   