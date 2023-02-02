#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int size);
    ~Queue(){delete [] Q;}
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int  dequeue();
    void Display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[this->size];
}

bool Queue::isFull()
{
    return rear == size-1;
}

bool Queue::isEmpty()
{
    return rear == front;
}

void Queue::enqueue(int x)
{
    if(isFull()) 
        cout << "Queue is full" << endl;
    else
        Q[++rear] = x;
}

int Queue::dequeue()
{
    int x = -1;
    if(isEmpty())
        cout << "Queue is Empty" << endl;
    else
        x = Q[++front];
    return x;
}

void Queue::Display()
{
    for (int i = front+1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}


int main()
{
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q(sizeof(A)/sizeof(A[0]));
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        q.enqueue(A[i]);
    
 
    // Display
    q.Display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        q.dequeue();
    
 
    // Underflow
    q.dequeue();

    return 0;
}