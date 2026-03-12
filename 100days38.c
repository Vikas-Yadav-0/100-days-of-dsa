#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1);
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

void push_front(int x)
{
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front > 0)
    {
        front--;
    }
    else
    {
        printf("Overflow\n");
        return;
    }
    deque[front] = x;
}

void push_back(int x)
{
    if(rear == MAX-1)
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void pop_front()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

int getFront()
{
    if(isEmpty())
        return -1;

    return deque[front];
}

int getBack()
{
    if(isEmpty())
        return -1;

    return deque[rear];
}

void clear()
{
    front = rear = -1;
}

void display()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    return 0;
}