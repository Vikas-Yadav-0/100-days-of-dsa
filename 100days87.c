#include <stdio.h>

// Iterative Binary Search Function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int n, target;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input sorted array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    scanf("%d", &target);

    // Perform Binary Search
    int result = binarySearch(arr, n, target);

    // Output result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}