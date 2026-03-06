#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push
void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop
int pop()
{
    if(top == NULL)
        return -1;

    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main()
{
    char exp[100];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while(token != NULL)
    {
        // If operand
        if(isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();
            int result;

            switch(token[0])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}