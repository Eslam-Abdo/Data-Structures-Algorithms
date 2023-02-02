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
    q->front = q->rear = 0;
    q->Q = (int*)malloc(q->size * sizeof(int));
}

int isFull(struct Queue q)
{
    return (q.rear+1)%q.size == q.front;
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
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(isEmpty(*q))
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i = (i+1) % q.size;
    }while(i != (q.rear+1)%q.size);
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
    enqueue(&q,50);
    enqueue(&q,60);

    Display(q);

    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    
    enqueue(&q,50);
    enqueue(&q,60);
    enqueue(&q,70);

    Display(q);

    return 0;
}

