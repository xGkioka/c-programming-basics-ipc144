#include <stdio.h>

void change1(int m){
    m = m * 2;
    printf("(In change1): the value of m is %d\n", m);
   
}
void change2(int *m) { // so this means the adress of m that is 10 in the main 
    *m = (*m) * 2; // and we multiply the *m witch is 10 to 20~
    printf("(in change2) the value stored at this adress (m) %x is %d\n", m, *m);
}
    

// POINTERS - its a special variable, its specialized to hold adresses and not regural values 
//  define - data type, *pointer name;
//example: int *ptr;  (will hold adress of integer value ) 

int main () {

int a = 5;  //variable is a container to hold value of a specific data type
printf("The value of a is %d\n",a); // this prints only the value of a
printf("The value of a in the memory is: %x \n", &a); // &a prints the adress in hex %x and &a
printf("The value of a is %d\n", *(&a));// the value stored at this adress of a 


int *ptr = &a; 

printf("The value stored at this address %x is %d\n", ptr, *ptr);
 //shows the hec (ptr) shows the stored value on the ptr with *ptr

 int m = 10;
 printf("(In main): the value of m is %d\n", m);
change1(m);
printf("(In main): the value of m is %d\n", m);
change2(&m);
printf("(In main): the value of m is %d\n", m);


    return 0;
}

