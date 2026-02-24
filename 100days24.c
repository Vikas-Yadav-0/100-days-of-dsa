#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Create node
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
    while(p->next) p = p->next;

    p->next = temp;
    return head;
}

// Delete first occurrence
struct Node* deleteKey(struct Node* head, int key){
    struct Node *temp = head, *prev = NULL;

    // if first node has key
    if(temp && temp->data == key){
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    // key not found
    if(temp == NULL) return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    int n, x, key;
    struct Node* head = NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head = insert(head,x);
    }

    scanf("%d",&key);

    head = deleteKey(head,key);
    display(head);

    return 0;
}