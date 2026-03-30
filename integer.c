#include <stdio.h>

int main() {
    int n, i, j, min_idx, temp;
    if (scanf("%d", &n) != 1) return 0;
 int nums[n];

 for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        temp = nums[min_idx];
        nums[min_idx] = nums[i];
        nums[i] = temp;
    }
    for (i = 0; i < n; i++) {
        printf("%d%s", nums[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
    return 0;
}
