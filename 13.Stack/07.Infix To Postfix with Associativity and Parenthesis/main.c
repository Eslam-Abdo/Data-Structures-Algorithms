#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node* next;
}*top=NULL;

void push(char x)
{
    struct Node* t;
    t = (struct Node*) malloc(sizeof(struct Node));
    if(t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    char x = -1;
    struct Node* t;
    if(top == NULL)
        printf("stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
char stackTop()
{
    return top? top->data : -1;
}
void Display()
{
    struct Node* p;
    p = top;
    while (p!=NULL)
    {
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i]!='\0' ; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == NULL)
                return 0;
            char temp = stackTop();
            if( exp[i] - temp == 2 || exp[i] - temp == 1)
                pop();
            else
                return 0;
        }
    }
    return top == NULL;
}

int isOperand(char x)
{
    return !(x == '+' || x == '-' || x == '*' || x == '/' ||
                x == '^' || x == '(' || x == ')');
}

int outPrecedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if(x == '^')
        return 6;
    else if(x == '(')
        return 7;
    else if(x == ')')
        return 0;
    return -1;   
}

int inPrecedence(char x)
{
    if(x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if(x == '^')
        return 5;
    else if(x == '(')
        return 0;
    return -1;   
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char*) malloc((len+1)* sizeof(char));

    while (infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(top == NULL || outPrecedence(infix[i]) > inPrecedence(top->data) )
                push(infix[i++]);
            else if(outPrecedence(infix[i]) == inPrecedence(top->data))
                pop();
            else
                postfix[j++] = pop();
        }
    }
    while (top != NULL && top->data != ')')
        postfix[j++] = pop();
    postfix[j] = '\0';
    
    return postfix;
}

int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    
    char *postfix=InToPost(infix);

    printf("%s \n",postfix);

    return 0;
}
