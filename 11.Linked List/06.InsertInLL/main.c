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


struct Node* LSearch(struct Node* p, int key)
{
    while(p)
    {
        if(p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node* LSearch_improve(struct Node* p, int key)
{
    struct Node *q=NULL;
    while(p)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node* p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next,key);
}

void Insert(struct Node*p, int index, int x)
{
    struct Node* t;

    if(index < 0 || index > Count(p))
        return;
    
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i=0; i<index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}



int main()
{
    struct Node* temp; 
    int A[] = {3,5,7,10,25,8,32,2};
    Create(A,8);

    Insert(first,4,5);

    Display(first);
    printf("\n");
    return 0;
}

