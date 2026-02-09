#include <stdio.h>
#define MAX_DEGREE 100

void addPolynomials(int poly1[], int poly2[], int sum[], int maxDeg) {
    for(int i = 0; i <= maxDeg; i++) {
        sum[i] = poly1[i] + poly2[i];
    }
}
void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%d", poly[i]);
            if (i > 0) printf("x^%d + ", i);
        }
    } printf("\n");
}int main() {
    int deg1, deg2, maxDeg;
    int poly1[MAX_DEGREE] = {0}, poly2[MAX_DEGREE] = {0}, sum[MAX_DEGREE] = {0};

    printf("Enter the highest degree for Region 1: ");
    scanf("%d", &deg1);
    for (int i = deg1; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    printf("\nEnter the highest degree for Region 2: ");
    scanf("%d", &deg2);
    for (int i = deg2; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    maxDeg = (deg1 > deg2) ? deg1 : deg2;
    addPolynomials(poly1, poly2, sum, maxDeg);

    printf("\nPower Consumption Analysis \n");
    printf("Region 1: "); displayPolynomial(poly1, deg1);
    printf("Region 2: "); displayPolynomial(poly2, deg2);
    printf("Combined: "); displayPolynomial(sum, maxDeg);

    return 0;
}
