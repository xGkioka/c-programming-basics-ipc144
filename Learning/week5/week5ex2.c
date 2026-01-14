#include <stdio.h>

int getInt(){
    int num;
    printf("Enter an Integer Number or 0 to exit\n");
    scanf("%d", &num);
    return num; 
 }

int main(void)
{
int sum =0;
int number;

number = getInt();

while(number!=0){
    sum = sum +number;
    number = getInt();
}
printf("The Sum is %d\n", sum);
    return 0;
}