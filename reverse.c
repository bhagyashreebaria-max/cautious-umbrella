#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d values:\n", n);
    for(i = 0; i < n; i++) {
        printf("Value - %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe values in reverse order are:\n");
    for(i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
