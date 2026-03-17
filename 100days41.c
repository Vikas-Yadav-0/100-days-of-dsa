#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation
int dequeue()
{
    if(front == NULL)
        return -1;

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main()
{
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}