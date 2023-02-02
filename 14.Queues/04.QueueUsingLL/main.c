#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Queue is full\n");
    else{
        temp->data = x;
        temp->next = NULL;
        if(front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node* temp;
    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void Display()
{
    struct Node* temp = front;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");    
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    Display();
    printf("%d \n",dequeue());

    return 0;
}
