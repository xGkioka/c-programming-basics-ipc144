#include <stdio.h>

void drawSquare(int n){
    int i, j;
    for (j=0; j < n; j++) { //numbers of row

        for (i = 0; i < n; i++)  { // numbers of lines
            if (j == 0 || j == n-1){
                printf("*");
            } else if (i>=1 && i<=n-2) {
                printf(" ");
            }
            else {  
                printf("*");
            }
        }
        //printf("*");  
//for (i = 0; i < j+1; i++)  {
        printf("*");
    } 
printf("\n");
} 
 

int main() {
    
drawSquare(5);
    return 0;
}