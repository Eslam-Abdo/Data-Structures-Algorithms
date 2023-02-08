#include "Queue.h"

#ifndef STACK_H
#define STACK_H

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void StackCreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **) malloc(st->size*sizeof(struct Node*));
}

void Stack_push(struct Stack *st,struct Node* x)
{
    if(st->top == st->size-1)
        printf("stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node* Stack_pop(struct Stack *st)
{
    struct Node* x = NULL;
    if(st->top == -1)
        printf("stack underflow\n");
    else
        x = st->S[st->top--];
    return x;
}

struct Node* Stack_peek(struct Stack st, int index)
{
    struct Node* x = NULL;
    if(st.top-index+1 < 0)
        printf("Invalid Index\n");
    else
        x = st.S[st.top-index+1];
    return x;
}

int Stack_isEmpty(struct Stack st)
{
    return st.top == -1;
}

int Stack_isFull(struct Stack st)
{
    return st.top == (st.size-1);
}

struct Node* StackTop(struct Stack st)
{
    if(!Stack_isEmpty(st))
        return st.S[st.top];
    return NULL;
}

#endif //STACK_H