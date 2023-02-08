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

void LevelOrder(struct Node* p)
{
    struct Queue q;
    QueueCreate(&q,100);
    printf("%d ",p->data);
    Queue_enqueue(&q,p);
    while (!Queue_isEmpty(q))
    {
        p = Queue_dequeue(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            Queue_enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            Queue_enqueue(&q,p->rchild);
        }
    }
    printf("\n");
}

int searchInorder(int inArr[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if(inArr[i] == data)
            return i;
    }
    return -1;
}

struct Node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIndex = 0;
    struct Node* temp;

    if(inStart > inEnd)
        return NULL;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = preorder[preIndex++];
    temp->lchild = temp->rchild = NULL;

    if(inStart == inEnd)
        return temp;

    int splitIndex = searchInorder(inorder,inStart, inEnd,temp->data);
    temp->lchild = generateFromTraversal(inorder,preorder,inStart,splitIndex-1);
    temp->rchild = generateFromTraversal(inorder,preorder,splitIndex+1, inEnd);

    return temp;
}

int Count(struct Node* p)
{
    return p? Count(p->lchild) + Count(p->rchild) + 1 : 0;
}

int Height(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return x > y? x+1 : y+1;
}

int Sum(struct Node* p)
{
    return p? Sum(p->lchild) + Sum(p->rchild) + p->data : 0;
}

int deg2NodeCount(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = deg2NodeCount(p->lchild);
    y = deg2NodeCount(p->rchild);

    return p->lchild && p->rchild? x+y+1 : x+y;
}

int leafNodeCount(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = leafNodeCount(p->lchild);
    y = leafNodeCount(p->rchild);

    return !p->lchild && !p->rchild? x+y+1 : x+y;
}

int deg1ordeg2NodeCount(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = deg1ordeg2NodeCount(p->lchild);
    y = deg1ordeg2NodeCount(p->rchild);

    return p->lchild || p->rchild? x+y+1 : x+y;
}

int deg1NodeCount(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = deg1NodeCount(p->lchild);
    y = deg1NodeCount(p->rchild);

    return p->lchild!=NULL ^ p->rchild!=NULL? x+y+1 : x+y;
}

int main()
{
    // TreeCreate();
 
    // int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    // int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    int preorder[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorder[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};

    root = generateFromTraversal(inorder,preorder,0, sizeof(inorder)/sizeof(inorder[0])-1);
 
    printf("preorder: ");
    iterativePreorder(root);
    printf("\n");

    printf("Count: %d\n",Count(root));
    printf("Height: %d\n",Height(root));
    printf("Sum: %d\n",Sum(root));
    printf("# of degree 2 nodes: %d\n",deg2NodeCount(root));
    printf("# of leaf nodes: %d\n",leafNodeCount(root));
    printf("# of degree 1 or degree 2 nodes: %d\n",deg1ordeg2NodeCount(root));
    printf("# of degree 1 nodes: %d\n",deg1NodeCount(root));

    printf("\n");
    return 0;
}
