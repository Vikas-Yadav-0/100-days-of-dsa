#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow");
        return;
    }

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if(front == -1)
        return;

    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}