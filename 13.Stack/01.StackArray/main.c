#include <stdio.h>
#include <stdlib.h>


struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d",&st->size);
    st->top = -1;
    st->S = (int*) malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
    for (int i = st.top; i>=0; i--)
        printf("%d ",st.S[i]);
    printf("\n");
}

void push(struct Stack *st,int x)
{
    if(st->top == st->size-1)
        printf("stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("stack underflow\n");
    else
        x = st->S[st->top--];
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top-index+1 < 0)
        printf("Invalid Index\n");
    else
        x = st.S[st.top-index+1];
    return x;
}

int isEmpty(struct Stack st)
{
    return st.top == -1;
}

int isFull(struct Stack st)
{
    return st.top == (st.size-1);
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    Create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    // push(&st,50);
    // push(&st,60);

    // printf("%d \n",isEmpty(st));
    // printf("%d \n",isFull(st));

    Display(st);

    return 0;
}
