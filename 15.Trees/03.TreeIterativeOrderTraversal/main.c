#include "Queue.h"
#include "Stack.h"

struct Node* root = NULL;

void TreeCreate()
{
    struct Node *t,*p;
    int x;
    struct Queue q;
    QueueCreate(&q,100);
    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Queue_enqueue(&q,root);
    while(!Queue_isEmpty(q))
    {
        p = Queue_dequeue(&q);
        printf("Enter Left child of %d : ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Queue_enqueue(&q,t);
        }
        printf("Enter Right child of %d : ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Queue_enqueue(&q,t);
        }
    }
}

void Preorder(struct Node* p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node* p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void iterativePreorder(struct Node* p)
{
    struct Stack stk;
    StackCreate(&stk,100);

    while (p != NULL || !Stack_isEmpty(stk))
    {
        if(p != NULL)
        {
            printf("%d ",p->data);
            Stack_push(&stk,p);
            p = p->lchild;
        }
        else
        {
            p = Stack_pop(&stk);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterativeInorder(struct Node* p)
{
    struct Stack stk;
    StackCreate(&stk,100);

    while (p != NULL || !Stack_isEmpty(stk))
    {
        if(p != NULL)
        {
            Stack_push(&stk,p);
            p = p->lchild;
        }
        else
        {
            p = Stack_pop(&stk);
            printf("%d ",p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterativePostorder(struct Node* p)
{
    struct Stack stk;
    long int temp;
    StackCreate(&stk,100);

    while (p != NULL || !Stack_isEmpty(stk))
    {
        if(p != NULL)
        {
            Stack_push(&stk,p);
            p = p->lchild;
        }
        else
        {
            temp = Stack_pop(&stk);
            if(temp > 0)
            {
                Stack_push(&stk,-temp);
                p = (struct Node*) temp;
                p = p->rchild;
            }
            else
            {
                p = (struct Node*) -temp;
                printf("%d ",p->data);
                p = NULL;
            }
        }
    }
    printf("\n");
}


int main()
{
    TreeCreate();

    printf("preorder: ");
    iterativePreorder(root);
    
    printf("Inorder: ");
    iterativeInorder(root);
    
    printf("postorder: ");
    iterativePostorder(root);

    printf("\n");
    return 0;
}
