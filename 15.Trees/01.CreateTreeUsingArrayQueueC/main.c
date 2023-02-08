#include "Queue.h"

struct Node* root = NULL;

void TreeCreate()
{
    struct Node *t,*p;
    int x;
    struct Queue q;
    Create(&q,100);
    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter Left child of %d : ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter Right child of %d : ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
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



int main()
{
    TreeCreate();

    printf("pre: ");
    Preorder(root);
    
    printf("\nIn: ");
    Inorder(root);
    
    printf("\npost: ");
    Postorder(root);

    printf("\n");
    return 0;
}
