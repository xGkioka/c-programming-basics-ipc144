#include<stdio.h>
#define SIZE 4 // defining a constant variable
int main() {
    int x = 5; 

    int arr1[4];
    // int arr1[SIZE]; // we can also use a constant variable to define the size of the array
    // int arr1[x]; // this is not allowed in C, the size must be a constant expression
arr1[0] = 10;
arr1[2] = 7;
arr1[3] = 20;

printf("%d\n", arr1[0]);
printf("arr1[%d] = %d\n", 0, arr1[0]);
printf("arr1[%d] = %d\n", 1, arr1[1]);
printf("arr1[%d] = %d\n", 2, arr1[2]);
printf("arr1[%d] = %d\n", 3, arr1[3]);
/* printf("arr1[%d] = %d\n", 4, arr1[4]); RUNTIME ERROR */

printf("-----------------------------\n");
// we can use a for loop beside writing each statement
// above to print all elements of the array
for (int i=0; i<SIZE;i++) {
    printf("arr1[%d] = %d\n", i, arr1[i]); 
}

printf("-----------------------------\n");
int arr2[SIZE]={ 7,2,3,5}; // initializing an array
for (int i=0; i<SIZE;i++) {
    printf("arr2[%d] = %d\n", i, arr2[i]); 
}

printf("-----------------------------\n");
int arr3[SIZE]={8,2}; 
for (int i=0; i<SIZE;i++) {
    printf("arr3[%d] = %d\n", i, arr3[i]); 
}


printf("-----------------------------\n");
int arr4[SIZE]={0}; // if we initialize an array with less elements than its size, the rest will be initialized to 0
for (int i=0; i<SIZE;i++) {
    printf("arr4[%d] = %d\n", i, arr4[i]); 
}

printf("-----------------------------\n");
int arr5[] = {3,2,5}; // if we don't specify the size of the array, it will be determined by the number of elements in the initializer
for (int i=0; i<3;i++) {
    printf("arr5[%d] = %d\n", i, arr5[i]); 
}
    return 0;

}   