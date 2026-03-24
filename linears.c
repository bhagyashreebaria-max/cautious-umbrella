#include <stdio.h>

int main() {
    int n,i, target, found = 0;

    
    printf("How many numbers in the array? ");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter %d integers:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }

    
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    
    for ( i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = 1; 
            break;     
        }
    }


    if (found == 1) {
        printf("Success! Value found at %d position .\n",i+1);
    } else {
        printf("Value %d not found in the array.\n", target);
    }

    return 0;
}
