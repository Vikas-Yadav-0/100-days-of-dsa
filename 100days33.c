#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        // Operand
        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // Left parenthesis
        else if(ch == '(')
        {
            push(ch);
        }

        // Right parenthesis
        else if(ch == ')')
        {
            while(peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}