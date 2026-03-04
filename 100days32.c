#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        return;   // Overflow case (not required to print)
    }
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        return;   // Underflow case (not required to print)
    }
    top--;
}

// Display remaining stack (Top to Bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    // Number of elements to push
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining elements
    display();

    return 0;
}