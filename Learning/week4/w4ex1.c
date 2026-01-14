#include <stdio.h>

int getNumMuffins(void);
double getUnitPrice(void);
double calculateTaxes(int numMuffins, double unitPrice);
void outputResult(int numMuffins, double unitPrice, double taxes);

int main(void) {   
    int numMuffins = getNumMuffins();
    double unitPrice = getUnitPrice();
    double tax = calculateTaxes(numMuffins, unitPrice);

    outputResult(numMuffins, unitPrice, tax);
    return 0;
}

int getNumMuffins(void) {
    int num;
    printf("Please enter the number of muffins purchased: ");
    scanf("%d", &num);
    return num;
}

double getUnitPrice(void) {
    double price;
    printf("Please enter the Price of each Muffin: ");
    scanf("%lf", &price);
    return price;
}

double calculateTaxes(int numMuffins, double unitPrice) {
    const double HST = 0.13;
    if (numMuffins < 6) {
        return numMuffins * unitPrice * HST;
    } else {
        return 0.0;
    }
}

void outputResult(int numMuffins, double unitPrice, double taxes) {
    double subtotal = numMuffins * unitPrice;
    double total = subtotal + taxes;

    printf("Cost of %d muffins at %.2lf each: %.2lf\n",
           numMuffins, unitPrice, subtotal);
    printf("Taxes: %.2lf\n", taxes);
    printf("Total: %.2lf\n", total);
}
