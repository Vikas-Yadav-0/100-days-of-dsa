#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// create node
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// insert at end in circular list
struct Node* insert(struct Node* head, int data){

    struct Node* temp = createNode(data);

    if(head == NULL){
        temp->next = temp;   // points to itself
        return temp;
    }

    struct Node* p = head;

    while(p->next != head)
        p = p->next;

    p->next = temp;
    temp->next = head;

    return head;
}

// display circular list
void display(struct Node* head){

    if(head == NULL) return;

    struct Node* p = head;

    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != head);
}

int main(){

    int n, x;
    struct Node* head = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head = insert(head,x);
    }

    display(head);

    return 0;
}