#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    while(index > 0 && heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(int index)
{
    int left, right, smallest;

    while(1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    if(size == MAX)
        return;

    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek()
{
    if(size == 0)
        return -1;

    return heap[0];
}

int extractMin()
{
    if(size == 0)
        return -1;

    int min = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main()
{
    int n, value;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
        else if(strcmp(op, "extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}