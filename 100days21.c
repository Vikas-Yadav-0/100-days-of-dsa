#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Function to create list
struct node* createList(int n)
{
    struct node *head = NULL, *temp, *newNode;

    for(int i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to traverse list
void traverse(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct node *head = createList(n);

    traverse(head);

    return 0;
}