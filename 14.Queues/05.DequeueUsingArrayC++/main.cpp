#include <iostream>
using namespace std;

class DEQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    DEQueue(int size);
    ~DEQueue(){delete [] Q;}
    bool isFull();
    bool isEmpty();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int  dequeueFront();
    int  dequeueRear();
    void Display();
};

DEQueue::DEQueue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[this->size];
}

bool DEQueue::isFull()
{
    return rear == size-1;
}

bool DEQueue::isEmpty()
{
    return rear == front;
}

void DEQueue::enqueueFront(int x)
{
    if(front == -1) 
        cout << "DEQueue overflow" << endl;
    else
        Q[front--] = x;
}

void DEQueue::enqueueRear(int x)
{
    if(isFull()) 
        cout << "DEQueue overflow" << endl;
    else
        Q[++rear] = x;
}

int DEQueue::dequeueFront()
{
    int x = -1;
    if(isEmpty())
        cout << "DEQueue underflow" << endl;
    else
        x = Q[++front];
    return x;
}

int DEQueue::dequeueRear()
{
    int x = -1;
    if(rear == -1)
        cout << "DEQueue underflow" << endl;
    else
        x = Q[rear--];
    return x;
}

void DEQueue::Display()
{
    for (int i = front+1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}


int main()
{
 
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEQueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.Display();
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    cout << endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.Display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.Display();
    deq.dequeueRear();
    deq.dequeueRear();

    return 0;
}