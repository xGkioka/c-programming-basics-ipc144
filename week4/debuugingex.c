#include <stdio.h>

double ShippingCost(int Weight, int Distance) {
    // Base cost
    double my_result = 10.75;

    // Extra $2.10 per kg over 5 kg
    if (Weight > 5) {
        my_result += 2.10 * (Weight - 5);
    }

    // Extra $0.05 per each 10 km over 600 km (round UP)
    if (Distance > 600) {
        int over = Distance - 600;
        int blocks = (over + 9) / 10;  // integer ceiling of over/10
        my_result += 0.05 * blocks;
    }

    return my_result;
}

int main() {
    int Weight, Distance;
    double cost;

    printf("Enter the weight of the package (in kg): ");
    scanf("%d", &Weight);
    printf("Enter the distance to be shipped (in km): ");
    scanf("%d", &Distance);

    cost = ShippingCost(Weight, Distance);
    printf("The shipping cost is: $%.2f\n", cost);

    return 0;
}
    