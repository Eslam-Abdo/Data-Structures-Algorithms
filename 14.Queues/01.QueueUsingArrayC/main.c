#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(q->size * sizeof(int));
}

int isFull(struct Queue q)
{
    return q.rear == q.size-1;
}

int isEmpty(struct Queue q)
{
    return q.rear == q.front;
}

void enqueue(struct Queue *q, int x)
{
    if(isFull(*q)) 
        printf("Queue is full\n");
    else
        q->Q[++(q->rear)] = x;
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(isEmpty(*q))
        printf("Queue is Empty\n");
    else
        x = q->Q[++(q->front)];
    return x;
}

void Display(struct Queue q)
{
    for (int i = q.front+1; i <= q.rear; i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}


int main()
{
    struct Queue q;
    Create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);

    Display(q);

    printf("%d \n",dequeue(&q));
    
    return 0;
}

