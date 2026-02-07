#include <stdio.h>

int main() {
    int n, pos;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete (1-based)
    scanf("%d", &pos);

    // Check if position is valid
    if(pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    // Shift elements to left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array (n-1 elements)
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
