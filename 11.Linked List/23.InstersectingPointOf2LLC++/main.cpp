#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node* Create(int A[], int n, Node* p = NULL)
{
    Node *head = new Node;
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
    last->next = p;
    return head;
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

void Intersection(Node* p, Node* q)
{
    stack<Node*> stk1, stk2;
    Node* r = NULL;
    /* Populate first stack */ 
    while (p!=NULL)
    {
        stk1.push(p);
        p = p->next;
    }
    /* Populate second stack */ 
    while (q!=NULL)
    {
        stk2.push(q);
        q = q->next;
    }
    /* get Intersecting Node */
    while (stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout << "Intersecting Node: "; 
    if(r!=NULL)cout << r->data; 
    else cout <<  "NULL !!"; 
    cout << endl;
}

int main()
{
    Node *first, *second;

    // Create First Linked List
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    first = Create(A, sizeof(A)/sizeof(A[0]));

    cout << "first LL: "; 
    Display(first);

    // Create Second Linked List
    Node* temp = first;
    int i = 5;
    while (i>0){
        temp = temp->next;
        i--;
    }
    cout << "intersection: " << temp->data << endl;
 
    int B[] = {2, 4, 6, 8, 10};
    second = Create(B, sizeof(B)/sizeof(B[0]),temp);
    cout << "second LL: "; 
    Display(second);

    Intersection(first, second);

    return 0;

}