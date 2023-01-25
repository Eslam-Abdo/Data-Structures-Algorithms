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

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);

    RDisplay(Head);

    printf("\n");
    return 0;
}

