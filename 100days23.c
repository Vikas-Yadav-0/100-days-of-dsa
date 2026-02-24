#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int data){
    struct Node* temp = createNode(data);

    if(head == NULL) return temp;

    struct Node* p = head;
    while(p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

// Merge two sorted lists
struct Node* merge(struct Node* l1, struct Node* l2){
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while(l1 && l2){
        struct Node* temp;

        if(l1->data < l2->data){
            temp = createNode(l1->data);
            l1 = l1->next;
        } else {
            temp = createNode(l2->data);
            l2 = l2->next;
        }

        if(result == NULL){
            result = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while(l1){
        tail->next = createNode(l1->data);
        tail = tail->next;
        l1 = l1->next;
    }

    while(l2){
        tail->next = createNode(l2->data);
        tail = tail->next;
        l2 = l2->next;
    }

    return result;
}

// Print list
void display(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        l1 = insert(l1,x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        l2 = insert(l2,x);
    }

    struct Node* merged = merge(l1,l2);
    display(merged);

    return 0;
}