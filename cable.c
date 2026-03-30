#include <stdio.h>

int main() {
    int n, i, j, temp;

    if (scanf("%d", &n) != 1) return 0;

    int viewing_times[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &viewing_times[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (viewing_times[j] > viewing_times[j + 1]) {
                temp = viewing_times[j];
                viewing_times[j] = viewing_times[j + 1];
                viewing_times[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d%s", viewing_times[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
