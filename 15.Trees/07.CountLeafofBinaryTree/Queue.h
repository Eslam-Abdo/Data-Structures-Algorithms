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

void QueueCreate(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node**)malloc(q->size * sizeof(struct Node*));
}

int Queue_isFull(struct Queue q)
{
    return (q.rear+1)%q.size == q.front;
}

int Queue_isEmpty(struct Queue q)
{
    return q.rear == q.front;
}

void Queue_enqueue(struct Queue *q, struct Node* x)
{
    if(Queue_isFull(*q)) 
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node* Queue_dequeue(struct Queue *q)
{
    struct Node* x = NULL;
    if(Queue_isEmpty(*q))
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

#endif // QUEUEU_H