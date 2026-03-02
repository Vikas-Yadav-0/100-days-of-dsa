#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

// create node
struct Node* createNode(int c, int e){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// insert at end
struct Node* insert(struct Node* head, int c, int e){

    struct Node* temp = createNode(c,e);

    if(head == NULL)
        return temp;

    struct Node* p = head;
    while(p->next)
        p = p->next;

    p->next = temp;
    return head;
}

// display polynomial
void display(struct Node* head){

    while(head){

        if(head->exp == 0)
            printf("%d", head->coeff);
        else if(head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);

        if(head->next)
            printf(" + ");

        head = head->next;
    }
}

int main(){

    int n, c, e;
    struct Node* head = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);
        head = insert(head,c,e);
    }

    display(head);

    return 0;
}