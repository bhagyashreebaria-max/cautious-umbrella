#include <stdio.h>

int main() {
    int n, i, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter index to delete (0 to %d): ", n - 1);
    scanf("%d", &index);

    for(i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
    }

    n--; 

    printf("New array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
