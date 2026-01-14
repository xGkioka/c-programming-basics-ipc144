#include<stdio.h>

double buy3GetOneFree(double unitPrice, int numUnits){
    int freeUnits = numUnits / 4; // Calculate the number of free units
    int payableUnits = numUnits - freeUnits; // Calculate the number of units to be paid for
    double totalCost = payableUnits * unitPrice; // Calculate the total cost
    return totalCost; // Return the total cost
}

int main(void){
    double unitPrice; // Variable declaration for unit price
    int numUnits; // Variable declaration for number of units
    printf("Enter the unit price: "); // Prompt the user for unit price
    scanf("%lf", &unitPrice); // Read the unit price
    printf("Enter the number of units: "); // Prompt the user for number of units
    scanf("%d", &numUnits); // Read the number of units
    double total = buy3GetOneFree(unitPrice, numUnits); // Function call to calculate total cost
    printf("Total cost: %.2lf\n", total); // Print the total cost
    return 0; // End of main function
}

/* double buy3GetOneFree(double unitPrice, int numUnits)
{
	int fourFullUnits;
	int leftOvers;
	double totalPrice;

	//every 4 units is charged as if 3 units were bought.
	//because division is truncated, only get number
	//of 4 full units in this calculation.  Example if there were 9 units,
	//this would be 9/4 = 2.
	fourFullUnits = numUnits/4;

	//this is the number of units that are essentially not part of the sale
	leftOvers = numUnits%4;

	totalPrice = unitPrice*3*fourFullUnits + leftOvers*unitPrice;
	return totalPrice;
    */