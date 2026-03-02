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

// Count occurrences
int countKey(struct Node* head, int key){
    int count = 0;

    while(head){
        if(head->data == key)
            count++;

        head = head->next;
    }

    return count;
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

    printf("%d", countKey(head,key));

    return 0;
}