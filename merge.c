#include <stdio.h>

int main() {
    int n1, n2, n3, i;

    printf("Enter size of 1st array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of 1st array: ");
    for(i = 0; i < n1; i++) scanf("%d", &arr1[i]);

    printf("Enter size of 2nd array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of 2nd array: ");
    for(i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    n3 = n1 + n2;
    int arr3[n3];

    for(i = 0; i < n1; i++) {
        arr3[i] = arr1[i];
    }
    for(i = 0; i < n2; i++) {
        arr3[n1 + i] = arr2[i];
    }
    printf("\nThe merged array is: ");

    for(i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
