#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = new Node;

void Create(int A[], int n)
{
    Node *temp,*last;

    head->data = A[0];
    head->next = NULL;
    last = head;

    // Create a Linked List
    for (int i = 1; i < n; i++)
    {
        // Create a temporary Node
        temp = new Node;
        // Populate temporary Node
        temp->data = A[i];
        temp->next = NULL;
        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
}

void Display(Node *p)
{
    // Display Linked List
    while (p != NULL)
    {
        cout << p->data <<  " ";
        p = p->next;
    }
    cout << endl;
}

void middleNode1(Node *p)
{
    /*get length of ll*/
    int len = 0;
    Node *q = p;
    while (q!=NULL)
    {
        len++;
        q = q->next;
    }
    /*get middle node*/
    int index = (int)ceil(len/2.0);
    for(int i=0; i<index-1; i++)
        p = p->next;
    cout << "Middle Element (Method-I): " << p->data << endl;
}

void middleNode2(Node *p)
{
    Node* q=p;
    while (q!=NULL)
    {
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    cout << "Middle Element (Method-II): " << p->data << endl;
}

void middleNode3(Node *p)
{
    stack<Node*> s;
    while (p)
    {
        s.push(p);
        p = p->next;
    }
    int len = s.size();
    int index_poplen = (int) floor(len/2.0);
    while (index_poplen)
    {
        s.pop();
        index_poplen--;
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl;
   
}

int main()
{
    int A[] = {3, 5, 7, 10, 15,20,23};

    Create(A,7);

    Display(head);
    middleNode1(head);
    middleNode2(head);
    middleNode3(head);

    return 0;

}