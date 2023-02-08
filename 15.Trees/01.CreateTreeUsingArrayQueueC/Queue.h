#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H


struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
};


struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node**)malloc(q->size * sizeof(struct Node*));
}

int isFull(struct Queue q)
{
    return (q.rear+1)%q.size == q.front;
}

int isEmpty(struct Queue q)
{
    return q.rear == q.front;
}

void enqueue(struct Queue *q, struct Node* x)
{
    if(isFull(*q)) 
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node* dequeue(struct Queue *q)
{
    struct Node* x = NULL;
    if(isEmpty(*q))
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}



#endif // QUEUE_H