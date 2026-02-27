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

// insert end
struct Node* insert(struct Node* head, int data){
    struct Node* temp = createNode(data);

    if(head == NULL) return temp;

    struct Node* p = head;
    while(p->next) p = p->next;
    p->next = temp;

    return head;
}

// length
int length(struct Node* head){
    int c = 0;
    while(head){
        c++;
        head = head->next;
    }
    return c;
}

// find intersection (value based as example)
int intersection(struct Node* h1, struct Node* h2){

    int l1 = length(h1);
    int l2 = length(h2);

    int diff = abs(l1 - l2);

    // move longer list
    if(l1 > l2)
        while(diff--) h1 = h1->next;
    else
        while(diff--) h2 = h2->next;

    // traverse together
    while(h1 && h2){
        if(h1->data == h2->data)
            return h1->data;

        h1 = h1->next;
        h2 = h2->next;
    }

    return -1;
}

int main(){
    int n,m,x;
    struct Node *h1=NULL,*h2=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        h1 = insert(h1,x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        h2 = insert(h2,x);
    }

    int ans = intersection(h1,h2);

    if(ans==-1) printf("No Intersection");
    else printf("%d",ans);

    return 0;
}