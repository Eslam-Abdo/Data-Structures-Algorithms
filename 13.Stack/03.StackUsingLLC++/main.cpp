#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;
public:
    Stack(){top = NULL;}
    ~Stack()
    {
        Node* p = top;
        while (top != NULL)
        {
            p = top;
            top = top->next;
            delete p;
        }
    }

    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
    void Display();
};

void Stack::push(int x)
{
    Node* t;
    t = new Node;
    if(t == NULL)
        cout << "stack is full" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    Node* t;
    if(top == NULL)
        cout << "stack is empty" << endl;
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int Stack::isFull()
{
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::isEmpty()
{
    return top == NULL;
}

int Stack::stackTop()
{
    return top? top->data : -1;
}

int Stack::peek(int index)
{
    if(isEmpty())
        return -1;
    else
    {
        Node* p = top;
        for(int i=0; p!=NULL && i<index-1; i++) 
            p = p->next;
        return p? p->data : -1;
    }
}

void Stack::Display()
{
    Node* p;
    p = top;
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;
    int A[] = {1,3,5, 7,9};
    // Populate stack
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        stk.push(A[i]);
    
    cout << "Stack peek at 3rd: " << stk.peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.peek(10) << endl;
    cout << "Stack top: " << stk.stackTop() << endl;
    cout << "Stack full: " << stk.isFull() << endl;
    cout << "Stack empty: " << stk.isEmpty() << endl;
    
    // Pop out elements from stack
    cout << "Popped: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
 
    // Underflow
    cout << stk.pop() << endl;


    return 0;
}
