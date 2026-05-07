#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
typedef struct {
    int value;
    int index;
} Element;

// Merge function
void merge(Element arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Element L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {

        // Right element is smaller
        if (R[j].value < L[i].value) {
            arr[k++] = R[j++];
            rightCount++;
        } else {

            // Count smaller elements on right
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
    }

    // Remaining left elements
    while (i < n1) {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    // Remaining right elements
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort function
void mergeSort(Element arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);

        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int nums[n];
    Element arr[n];
    int count[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        arr[i].value = nums[i];
        arr[i].index = i;

        count[i] = 0;
    }

    // Perform merge sort counting
    mergeSort(arr, 0, n - 1, count);

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}