#include<stdio.h>

#define SIZE 100


int main(){
    char name1[SIZE] = {'X','e','n','o','f','o','n','\0'}; // not a C-string as it does not have null character at the end
    for (int i=0; i<7; i++){
        printf("%c", name1[i]);
    }

    printf("\n-----------------------------\n");
    char name2[] = {'X','e','n','o','\0','f','o','n','\0'}; // null character to indicate the end of the string
    for (int i=0; i<7; i++){
        printf("%c", name2[i]);
    }

    printf("\n-----------------------------\n");
    printf("%s\n", name2); // print the string until the null character    
    printf("\n-----------------------------\n");
    printf("%s\n", name1); //  NOT ACCEPTER CZ NAME1 IS NOT C-STRING
    printf("\n-----------------------------\n");
    char name3[SIZE+1] = "Xenofon"; // string literal, compiler automatically adds null character at the end
    printf("%s\n", name3);
    return 0;

}