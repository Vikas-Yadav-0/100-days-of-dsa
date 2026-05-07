#include <stdio.h>
#include <stdlib.h>

// Structure for meetings
typedef struct {
    int start;
    int end;
} Meeting;

// Function to compare meetings by start time
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Min-Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify down
void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[smallest], &heap[index]);
        heapifyDown(heap, size, smallest);
    }
}

// Function to find minimum meeting rooms
int minMeetingRooms(Meeting meetings[], int n) {

    // Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    // Add first meeting end time
    heap[heapSize++] = meetings[0].end;

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {

        // If earliest meeting room is free
        if (meetings[i].start >= heap[0]) {
            heap[0] = meetings[i].end;
            heapifyDown(heap, heapSize, 0);
        } else {
            // Need new room
            heap[heapSize] = meetings[i].end;
            heapifyUp(heap, heapSize);
            heapSize++;
        }

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    return maxRooms;
}

int main() {
    int n;

    // Input number of meetings
    scanf("%d", &n);

    Meeting meetings[n];

    // Input meeting intervals
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    // Output minimum rooms required
    printf("%d\n", minMeetingRooms(meetings, n));

    return 0;
}