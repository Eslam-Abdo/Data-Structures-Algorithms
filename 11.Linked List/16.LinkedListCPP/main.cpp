#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* first;
public:
    LinkedList(){first=NULL;}
    LinkedList(int A[],int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList()
{
    Node* p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node* p = first;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length()
{
    Node *p = first;
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void LinkedList::Insert(int index, int x)
{
    Node *p = first, *t;

    if(index < 0 || index > Length())
        return;
    
    t = new Node;
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

int LinkedList::Delete(int index)
{
    Node* q = NULL, *p = first;
    int x = -1;

    if(index < 1 || index > Length())
        return x;
    if(index == 1)
    {
        x = first->data;
        first = first->next;
        delete p;
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
            delete p;
            return x;
        }
    }
    return x;
}



int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    
    l.Insert(3,10);
    l.Display();

    return 0;
}
