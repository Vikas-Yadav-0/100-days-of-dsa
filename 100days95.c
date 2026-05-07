#include <stdio.h>
#include <stdlib.h>

// Structure for bucket node
struct Node {
    float data;
    struct Node* next;
};

// Function to insert into sorted linked list
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse and insert
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort Function
void bucketSort(float arr[], int n) {

    // Create n buckets
    struct Node* buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets into array
    int k = 0;

    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    float arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Perform Bucket Sort
    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}