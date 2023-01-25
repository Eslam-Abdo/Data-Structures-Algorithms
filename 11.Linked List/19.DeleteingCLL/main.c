#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node* next;
}*Head;

void Create(int A[], int n)
{
    struct Node *t, *last;
    Head = (struct Node*) malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* h)
{
    if(Head == NULL)
    {
        printf("empty LL!!\n");
        return;
    }
    do
    {
        printf("%d ",h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

void RDisplay(struct Node* h)
{
    static int flag = 0;
    if(h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node* h)
{
    int len = 0;
    do
    {
        len++;
        h = h->next;
    } while (h != Head);
    return len;
}

void Insert(struct Node* h, int index, int x)
{
    struct Node* t;
    if(index < 0 || index > Length(h))
        return;
    if(index == 0)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        if(Head == NULL)
        {
            Head = t;
            t->next = Head;
        }
        else
        {
            while(h->next != Head) h = h->next;
            h->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (int i = 0; i < index-1; i++) h = h->next;
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        t->next = h->next;
        h->next = t;
    }
}

int Delete(struct Node* h, int index)
{
    struct Node* q;
    int x = -1;
    if(index < 1 || index > Length(h))
        return x;
    if(index == 1)
    {
        while(h->next != Head) h = h->next;
        x = Head->data;
        if(h == Head)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            h->next = Head->next;
            free(Head);
            Head = h->next;
        }
    }
    else
    {
        for (int i = 0; i < index-2; i++) h = h->next;
        q = h->next;
        h->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);

    printf("Delete element: %d\n", Delete(Head, 1));

    Display(Head);
    printf("\n");
    return 0;
}

