#include <stdio.h>

// Function to return maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to check if boards can be painted
// within given maximum time
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {

        // If a single board is greater than maxTime
        if (boards[i] > maxTime)
            return 0;

        // Assign board to next painter
        if (total + boards[i] > maxTime) {
            painters++;
            total = boards[i];

            if (painters > k)
                return 0;
        } else {
            total += boards[i];
        }
    }

    return 1;
}

// Function to find minimum painting time
int painterPartition(int boards[], int n, int k) {
    int low = 0, high = 0;
    int ans = -1;

    // Find search space
    for (int i = 0; i < n; i++) {
        low = max(low, boards[i]);
        high += boards[i];
    }

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller value
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    // Input number of boards and painters
    scanf("%d %d", &n, &k);

    int boards[n];

    // Input board lengths
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    // Print minimum time required
    printf("%d\n", painterPartition(boards, n, k));

    return 0;
}