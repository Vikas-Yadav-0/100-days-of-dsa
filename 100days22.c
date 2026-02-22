#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Create list
struct node* create(int n)
{
    struct node *head=NULL,*temp,*newNode;

    for(int i=0;i<n;i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        if(head==NULL)
            head=temp=newNode;
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
    return head;
}

// Count nodes
int countNodes(struct node *head)
{
    int count=0;
    struct node *temp=head;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);

    struct node *head=create(n);

    printf("%d",countNodes(head));

    return 0;
}