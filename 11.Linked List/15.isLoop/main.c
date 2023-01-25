#include <stdio.h>
#include <stdlib.h>

#define INT32_MIN   -65536


struct Node
{
    int data;
    struct Node* next;
}*first=NULL, *last=NULL, *second=NULL, *thrid=NULL;

struct Node* Create(int A[],int n)
{
    struct Node *p, *t, *last;
    p = (struct Node*) malloc(sizeof(struct Node));
    p->data = A[0];
    p->next = NULL;
    last = p;

    for(int i=1; i<n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return p;
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


void InsertLast(int x)
{
    struct Node* t;
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

void SortedInsert(struct Node*p, int x)
{
    struct Node *t,*q = NULL;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t; 
        }
    }

}

int Delete(struct Node* p, int index)
{
    struct Node* q = NULL;
    int x = -1;

    if(index < 1 || index > Count(p))
        return x;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;   
        }
        if(p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
            return x;
        }
    }
}

int isSorted(struct Node* p)
{
    int x = INT32_MIN;
    while (p)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node*p)
{
    struct Node* q = p->next;

    while (q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
/* reverse elements using array*/
void Reverse1(struct Node* p)
{
    int i = 0;
    int *A;
    A = (int*) malloc(sizeof(int)* Count(p));

    struct Node* q=p;
    while (q!=NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q!=NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
/* reverse links using sliding pointers */
void Reverse2(struct Node* p)
{
    struct Node *q,*r;
    q = r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
/* reverse links using recursion */
void Reverse3(struct Node* q, struct Node* p)
{
    if(p != NULL)
    {
        Reverse3(p,p->next);
        p->next = q;
    }
    else
        first = q;
}

void Concat(struct Node*f, struct Node* s)
{
    thrid = f;
    while(f->next != NULL)
        f = f->next;
    f->next = s;
}
void Merge(struct Node*f, struct Node* s)
{
    struct Node* last;

    if(f->data < s->data)
    {
        thrid = last = f;
        f = f->next;
        thrid->next = NULL;
    }
    else
    {
        thrid = last = s;
        s = s->next;
        thrid->next = NULL;
    }
    while (f && s)
    {
        if(f->data < s->data)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;

        }
        else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }
    if(f)last->next=f;
    if(s)last->next=s;
}

int isLoop(struct Node* p)
{
    struct Node *r, *q; 
    r = q = p;
    do
    {
        r = r->next;
        q = q->next;
        q = q? q->next : q;
    } while (r && q && r!=q);
    
    return r == q ? 1: 0;
}


int main()
{
    struct Node *t1, *t2;
    int A[]={10,20,30,40,50};
    first = Create(A,5);

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

    printf("isLOOP? %s"
            ,isLoop(first)? "yes" : "no");

    printf("\n");
    return 0;
}

