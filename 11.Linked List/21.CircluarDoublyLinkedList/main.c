#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*Head;


void Create(int A[], int n)
{
    struct Node *t, *last;
    Head = (struct Node*) malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->prev = Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];

        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
        Head->prev = last;
    }   
}

void Display(struct Node* p)
{
    if(p == NULL)
    {
        printf("empty!!\n");
        return;
    }
    do
    {
        printf("%d ",p->data);
        p = p->next;
    }while(p != Head);
    printf("\n");   
}

int Length(struct Node* p)
{
    int len = 0;
    do
    {
        len++;
        p = p!=NULL? p->next : p;
    }while (p != Head);
    return len;
}

void Insert(struct Node* p, int index, int x)
{
    struct Node* t;
    if(index < 0 || index > Length(p))
        return;
    if(index == 0)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;

        if(Head == NULL)
        {
            Head = t;
            Head->next = Head->prev = Head;
        }
        else
        {
            t->prev = Head->prev;
            t->next = Head;

            Head->prev->next = t;
            Head->prev = t;
            Head = t;
        }
    }
    else
    {
        for(int i = 0 ; i < index-1; i++)
            p = p->next;
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node* p, int index)
{
    int x = -1;
    if(index < 1 || index > Length(p) || p == NULL)
        return x;
    if(index == 1)
    {
        if(Head->next == Head)
        {
            x = p->data;
            free(Head);
            Head = NULL;
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            Head = p->next;
            x = p->data;
            free(p);
        }
    }
    else
    {
        for(int i=0; i < index-1; i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {10,20,30,40,50};
    // Create(A,5);

    Insert(Head,0,35);
    // Insert(Head,0,50);
    // Insert(Head,1,25);

    Display(Head);

    Delete(Head,1);

    Display(Head);
    printf("\n");
    return 0;
}
