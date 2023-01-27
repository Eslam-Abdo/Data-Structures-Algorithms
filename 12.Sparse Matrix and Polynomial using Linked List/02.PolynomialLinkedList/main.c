#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* Create()
{
    struct  Node *head=NULL,*t,*last;
    int num;

    printf("Enter number of terms: ");
    scanf("%d",&num);
    printf("Enter each term with coeff and exp\n");
    for (int i = 0; i < num; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff,&t->exp);
        t->next = NULL;
        if(head == NULL)
            head = last = t;
        else
        {
            last->next = t;
            last = t;
        }
    }
    return head;
}

void Display(struct Node* p)
{
    while (p->next != NULL)
    {
        printf("%dx%d + ",p->coeff, p->exp);
        p = p->next;
    }
    printf("%dx%d \n",p->coeff, p->exp);
}

long Eval(struct Node *p, int x)
{
    long val = 0;
    while (p!=NULL)
    {
        val += p->coeff * pow(x,p->exp);
        p = p->next;
    }
    return val;
}

struct Node* Add(struct Node* p, struct Node* q)
{

    struct Node *sum,*tail, *temp;

    while (p&&q)
    {
        if(p->exp > q->exp)
        {
            temp = (struct Node*)malloc(sizeof(struct Node));;
            temp->exp = p->exp;
            temp->coeff = p->coeff;
            temp->next = NULL;
            p = p->next;

        }
        else if(p->exp < q->exp)
        {
            temp = (struct Node*)malloc(sizeof(struct Node));;
            temp->exp = q->exp;
            temp->coeff = q->coeff;
            temp->next = NULL;
            q = q->next;

        }
        else /* p->exp == q->exp */
        {
            temp = (struct Node*)malloc(sizeof(struct Node));;
            temp->exp = p->exp;
            temp->coeff = p->coeff + q->coeff;
            temp->next = NULL;

            p = p->next;
            q = q->next;
        }
        if(sum == NULL)
            sum = tail = temp;
        else
        {
            tail->next = temp;
            tail= tail->next;
        }
    }
    if (p) tail->next = p;
    if (q) tail->next = q;       
    
    return sum;
}

int main()
{
    struct Node *poly_1=NULL, *poly_2=NULL, *sum;


    printf("first poly: \n");
    poly_1 = Create();
    Display(poly_1);
    printf("%ld\n",Eval(poly_1,1));

    printf("second poly: \n");
    poly_2 = Create();
    Display(poly_2);
    printf("%ld\n",Eval(poly_2,1));

    printf("\nadd: ");
    sum = Add(poly_1,poly_2);
    Display(sum);

    return 0;
}
