#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to check if painting is possible
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {

        // If a single board is larger than maxTime
        if (boards[i] > maxTime)
            return 0;

        // Assign to next painter
        if (currentTime + boards[i] > maxTime) {
            painters++;
            currentTime = boards[i];

            if (painters > k)
                return 0;
        } else {
            currentTime += boards[i];
        }
    }

    return 1;
}

// Function to find minimum painting time
int painterPartition(int boards[], int n, int k) {
    int low = 0, high = 0;
    int ans = -1;

    // Calculate search range
    for (int i = 0; i < n; i++) {
        low = max(low, boards[i]);
        high += boards[i];
    }

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller maximum time
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

    // Output result
    printf("%d\n", painterPartition(boards, n, k));

    return 0;
}