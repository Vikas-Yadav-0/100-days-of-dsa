#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int data){
    struct Node* temp = createNode(data);

    if(head == NULL) return temp;

    struct Node* p = head;
    while(p->next) p = p->next;

    p->next = temp;
    temp->prev = p;

    return head;
}

// Display forward
void display(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
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