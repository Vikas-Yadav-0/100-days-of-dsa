#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start;
    int end;
} Interval;

// Function to compare intervals by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {

    // Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array for merged intervals
    Interval merged[n];
    int index = 0;

    // Add first interval
    merged[index] = arr[0];

    for (int i = 1; i < n; i++) {

        // Check overlap
        if (arr[i].start <= merged[index].end) {

            // Merge intervals
            if (arr[i].end > merged[index].end) {
                merged[index].end = arr[i].end;
            }

        } else {

            // No overlap, move to next interval
            index++;
            merged[index] = arr[i];
        }
    }

    // Print merged intervals
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }
}

int main() {
    int n;

    // Input number of intervals
    scanf("%d", &n);

    Interval arr[n];

    // Input intervals
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Merge and print intervals
    mergeIntervals(arr, n);

    return 0;
}