#include <iostream>
using namespace std;

#ifndef QUEUE_CPP_H
#define QUEUE_CPP_H

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(int size);
    ~Queue(){delete [] Q;}
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node*  dequeue();
    // void Display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new Node*[this->size];
}

bool Queue::isFull()
{
    return rear == size-1;
}

bool Queue::isEmpty()
{
    return rear == front;
}

void Queue::enqueue(Node* x)
{
    if(isFull()) 
        cout << "Queue is full" << endl;
    else
        Q[++rear] = x;
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if(isEmpty())
        cout << "Queue is Empty" << endl;
    else
        x = Q[++front];
    return x;
}

// void Queue::Display()
// {
//     for (int i = front+1; i <= rear; i++)
//         cout << Q[i] << " ";
//     cout << endl;
// }




#endif //QUEUE_CPP_H