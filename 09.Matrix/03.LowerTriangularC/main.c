#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};
/* Row major method (fourmal: i*(i-1)/2 + j-1 )*/
void Set_RowMajor(struct Matrix *m, int i, int j, int x)
{
    if(i >= j) m->A[i*(i-1)/2 + j-1] = x;
}
int Get_RowMajor(struct Matrix m, int i, int j)
{
    if(i >= j) return m.A[i*(i-1)/2 + j-1];
    else       return 0;
}
void Display_RowMajor(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if(i >= j)
                printf("%d ",m.A[i*(i-1)/2 + j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }  
} 

/* column major method (fourmal: n(j-1) + (j-1)(j-2)/2 + i-j )*/

void Set_ColMajor(struct Matrix *m, int i, int j, int x)
{
    if(i >= j) m->A[m->n*(j-1) - (j-1)*(j-2)/2 + i-j] = x;
}
int Get_ColMajor(struct Matrix m, int i, int j)
{
    if(i >= j) return m.A[m.n*(j-1) - (j-1)*(j-2)/2 + i-j];
    else       return 0;
}
void Display_ColMajor(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if(i >= j)
                printf("%d ",m.A[m.n*(j-1) - (j-1)*(j-2)/2 + i-j]);
            else
                printf("0 ");
        }
        printf("\n");
    }  
}

int main()
{
    struct Matrix m;
    int x;
    printf("Enter Dimensions ");
    scanf("%d",&m.n);    

    m.A = (int*) malloc(m.n*(m.n -1)/2*sizeof(int));

    printf("Enter All Elements\n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d",&x);
            Set_ColMajor(&m, i,j,x);
        }
    }
    printf("\n\n");
    Display_ColMajor(m);

    return 0;
}
