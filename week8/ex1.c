#include<stdio.h>

struct Book
{
char title[100];
char author[50];
int year;
float price;
};

int main () {

    struct Book book1={"John","Tittle",2025,25};
    printf("Author: %s\n", book1.author);
    printf("Title: %s\n", book1.title);
    printf("Year: %d\n", book1.year);
    printf("Price: %.2lf\n", book1.price);




    return 0;
}