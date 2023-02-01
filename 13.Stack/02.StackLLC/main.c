#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    // Display();

    printf("%d \n",pop());
    Display();

    return 0;
}
