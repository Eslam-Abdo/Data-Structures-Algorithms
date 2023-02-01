#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
}*top=NULL;

void push(int x)
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

int pop()
{
    int x = -1;
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
int stackTop()
{
    return top? top->data : -1;
}
void Display()
{
    struct Node* p;
    p = top;
    while (p!=NULL)
    {
        printf("%d ",p->data);
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
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;   
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
            if(top == NULL || pre(infix[i]) > pre(top->data) )
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;
}

int Eval(char *postfix)
{
    int x1,x2,r=0;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop(); x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }    
    }
    return top->data;
}


int main()
{
    char *infix = "2+3*4-8/2";
    char *postfix=InToPost(infix);
    printf("%s \n",postfix);

    // postfix="234*+82/-";
    printf("Result is %d\n",Eval(postfix));

    return 0;
}
