#include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;   // Store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;

    // Input
    scanf("%d", &n);

    // Output
    printf("%d\n", integerSquareRoot(n));

    return 0;
}