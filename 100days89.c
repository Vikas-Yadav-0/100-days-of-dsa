#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to check if allocation is possible
int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        // If a single book has more pages than maxPages
        if (books[i] > maxPages)
            return 0;

        // Allocate to next student
        if (pagesSum + books[i] > maxPages) {
            students++;
            pagesSum = books[i];

            if (students > m)
                return 0;
        } else {
            pagesSum += books[i];
        }
    }

    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int books[], int n, int m) {
    int low = 0, high = 0;
    int ans = -1;

    // Calculate search range
    for (int i = 0; i < n; i++) {
        low = max(low, books[i]);
        high += books[i];
    }

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller maximum
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;

    // Input number of books and students
    scanf("%d %d", &n, &m);

    int books[n];

    // Input pages in books
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    // Output result
    printf("%d\n", allocateBooks(books, n, m));

    return 0;
}