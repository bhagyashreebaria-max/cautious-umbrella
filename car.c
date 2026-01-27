#include <stdio.h>

struct Car {
    int id;
    char model[20];
    float rate;
};
int main() {
    struct Car cars[3];
    int days;
    float total = 0;

    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Car %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &cars[i].id);
        printf("Model: ");
        scanf("%s", cars[i].model);
        printf("Rate per day: ");
        scanf("%f", &cars[i].rate);
    }
    printf("\nEnter number of rental days: ");
    scanf("%d", &days);

    printf("\n Rental Details \n");
    for (int i = 0; i < 3; i++) {
        float cost = cars[i].rate * days; 
        printf("Car %d (%s): $%.2f\n", cars[i].id, cars[i].model, cost);
        total += cost;
    }

    printf("\nTotal Bill for all cars: $%.2f\n", total);

    return 0;
}
