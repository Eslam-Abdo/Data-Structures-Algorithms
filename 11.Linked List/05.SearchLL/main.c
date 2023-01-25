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

int main()
{
    struct Node* temp; 
    int A[] = {3,5,7,10,25,8,32,2};
    Create(A,8);

    temp = LSearch_improve(first, 25);
    temp = LSearch_improve(first, 32);
    if(temp)
        printf("key is found : %d\n",temp->data);
    else
        printf("key not found\n");

    Display(first);
    printf("\n");
    return 0;
}

