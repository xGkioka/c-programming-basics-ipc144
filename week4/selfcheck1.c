#include <stdio.h>

// prototype
double findPopCornPrice(char size, int hasButter, int hasSeaoning);

int main(void) {
    char size; 
    int hasButter;
    int hasSeaoning;
    double price;   

    printf("Enter the size of the popcorn (S, M, L): ");
    scanf(" %c", &size);

    printf("Do you want butter? (1 for yes, 0 for no): ");
    scanf("%d", &hasButter);

    printf("Do you want seasoning? (1 for yes, 0 for no): ");
    scanf("%d", &hasSeaoning);      

    price = findPopCornPrice(size, hasButter, hasSeaoning);

    printf("The total price of the popcorn is: $%.2f\n", price);

    return 0;
}

// definition
double findPopCornPrice(char size, int hasButter, int hasSeaoning) {
    double total = 0.0;

    if (size == 'S' || size == 's') total = 5.0;
    else if (size == 'M' || size == 'm') total = 6.0;
    else if (size == 'L' || size == 'l') total = 8.0;
    else {
        printf("Invalid size! Please enter S, M, or L.\n");
        return -1; // error code
    }

    if (hasButter) total += 1.0;
    if (hasSeaoning) total += 0.5;

    return total;
}
