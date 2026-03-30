#include <stdio.h>

int main() {
    int n, i, x;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d", &x) != 1) return 0;
    int low = 0, high = n - 1;
    int found_index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            found_index = mid;
            break;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found_index != -1) {
        printf("The target value %d is present at index %d\n", x, found_index);
    } else {
        printf("The target value %d is not present in the array\n", x);
    }

    return 0;
}
