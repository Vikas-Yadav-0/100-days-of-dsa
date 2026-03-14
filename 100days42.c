#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        enqueue(x);
    }

    // Step 1: queue → stack
    for(int i=0;i<n;i++)
        push(dequeue());

    // Step 2: stack → queue
    for(int i=0;i<n;i++)
        enqueue(pop());

    // Print reversed queue
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    return 0;
}