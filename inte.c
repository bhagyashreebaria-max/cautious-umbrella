#include <stdio.h>

int main() {
    int n, i, key;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d", &key) != 1) return 0;

    int low = 0, high = n - 1;
    int count = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= key) {
            count = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", count);

    return 0;
}
