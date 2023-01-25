#include <stdio.h>
#include <stdlib.h>



struct Node
{
    int data;
    struct Node* next;
}*first = NULL;

void Create(int A[],int n)
{
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        RDisplay(p->next);
        printf("%d ",p->data);
    }
}


int main()
{

    int A[] = {3,5,7,10,25,8,32,2};

    Create(A,8);
    RDisplay(first);
    // Display(first);

    printf("\n");
    return 0;
}

