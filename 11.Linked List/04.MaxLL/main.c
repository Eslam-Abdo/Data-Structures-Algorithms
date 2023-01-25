#include <stdio.h>
#include <stdlib.h>

#define INT32_MIN   -65536

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

int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if(max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x = 0;
    if(p == NULL)
        return INT32_MIN;
    x = RMax(p->next);
    return (x > p->data) ? x : p->data;
}


int main()
{

    int A[] = {3,5,7,10,25,8,32,2};

    Create(A,8);
    // RDisplay(first);
    // Display(first);

    // printf("Max: %d\n", Max(first));
    printf("Max: %d\n", RMax(first));
    printf("\n");
    return 0;
}

