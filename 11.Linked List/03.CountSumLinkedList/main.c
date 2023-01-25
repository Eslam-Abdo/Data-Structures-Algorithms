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

int Count(struct Node *p)
{
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int RCount(struct Node *p)
{
    if(p != NULL)
        return RCount(p->next) + 1;
    else 
        return 0;
}

int Sum(struct Node*p)
{
    int s = 0;
    while(p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int RSum(struct Node*p)
{
    if(p != NULL)
        return RSum(p->next) + p->data;
    else 
        return 0;
}

int main()
{

    int A[] = {3,5,7,10,25,8,32,2};

    Create(A,8);
    // Display(first);

    // printf("%d\n",Count(first));
    // printf("%d\n",RCount(first));
    // printf("sum is : %d\n",Sum(first));
    printf("sum is : %d\n",RSum(first));

    printf("\n");
    return 0;
}

