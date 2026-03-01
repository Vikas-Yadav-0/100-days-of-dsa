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

// insert at end
struct Node* insert(struct Node* head, int data){
    struct Node* temp = createNode(data);

    if(head == NULL) return temp;

    struct Node* p = head;
    while(p->next) p = p->next;
    p->next = temp;

    return head;
}

// rotate function
struct Node* rotateRight(struct Node* head, int k){

    if(!head || !head->next || k == 0)
        return head;

    // find length and last node
    struct Node* temp = head;
    int n = 1;

    while(temp->next){
        temp = temp->next;
        n++;
    }

    k = k % n;
    if(k == 0) return head;

    // make circular
    temp->next = head;

    // move to (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;

    for(int i=1; i<steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// display
void display(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){

    int n, x, k;
    struct Node* head = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head = insert(head,x);
    }

    scanf("%d",&k);

    head = rotateRight(head,k);
    display(head);

    return 0;
}