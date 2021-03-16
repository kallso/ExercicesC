#include <stdio.h>

int main() {
    double taux2dollar = 1.11792, taux2euro = 0.894521;
    double dollar = 4373.00, euro = 101.63;

    double dollar2euro = dollar * taux2euro;
    double euros2dollar = euro * taux2dollar;

    printf("%.2f $ = %.2f € \n", dollar, dollar2euro);
    printf("%.2f € = %.2f $ \n", euro, euros2dollar);
}
