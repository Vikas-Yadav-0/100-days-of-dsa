#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if cows can be placed
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // First cow placed at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }

        if (count >= k)
            return 1;
    }

    return 0;
}

// Function to find maximum minimum distance
int aggressiveCows(int stalls[], int n, int k) {
    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;      // Possible answer
            low = mid + 1;  // Try for larger distance
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    // Input number of stalls and cows
    scanf("%d %d", &n, &k);

    int stalls[n];

    // Input stall positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Output result
    printf("%d\n", aggressiveCows(stalls, n, k));

    return 0;
}