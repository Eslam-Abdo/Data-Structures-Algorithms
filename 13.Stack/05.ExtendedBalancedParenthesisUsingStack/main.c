#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    char A[] = "{([a+b]*[c-d])/e}";
    char B[] = "{([a+b]}*[c-d])/e}";
    char C[] = "{([{a+b]*[c-d])/e}";
    
    printf("%d \n",isBalanced(A));
    printf("%d \n",isBalanced(B));
    printf("%d \n",isBalanced(C));

    return 0;
}
