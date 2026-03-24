#include <stdio.h>

int main() {
    int n, target, temp;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    
    printf("Enter value to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == target) {
            found = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    if (found != -1) printf("Found %d at sorted index %d.\n", target, mid+1);
    else printf("Not found.\n");

    return 0;
}
