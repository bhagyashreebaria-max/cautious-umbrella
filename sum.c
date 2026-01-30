#include <stdio.h>

int main() {
    int n, i;
    int sum = 0; 

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        sum += arr[i]; 
    }
    printf("\nThe sum of all elements in the array is: %d\n", sum);

    return 0;
}
