#include <stdio.h>

// Function to merge two subarrays and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // Left subarray index
    int j = mid + 1;   // Right subarray index
    int k = left;      // Temp array index
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // Remaining elements in left subarray
            // form inversions
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// Modified Merge Sort function
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in left half
        invCount += mergeSort(arr, temp, left, mid);

        // Count inversions in right half
        invCount += mergeSort(arr, temp, mid + 1, right);

        // Count split inversions
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int arr[n], temp[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count inversions
    long long inversions = mergeSort(arr, temp, 0, n - 1);

    // Print inversion count
    printf("%lld\n", inversions);

    return 0;
}