#include <stdio.h>
#include <stdlib.h>


int main()
{
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    printf("+++++++++++++++++++++++++++++++++\n");

    int *B[3];
    B[0] = (int*) malloc(4*sizeof(int));
    B[1] = (int*) malloc(4*sizeof(int));
    B[2] = (int*) malloc(4*sizeof(int));

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }
    printf("+++++++++++++++++++++++++++++++++\n");

    int **C;
    C = (int**) malloc(3*sizeof(int*));
    C[0] = (int*) malloc(4*sizeof(int));
    C[1] = (int*) malloc(4*sizeof(int));
    C[2] = (int*) malloc(4*sizeof(int));

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
    printf("+++++++++++++++++++++++++++++++++\n");    

    


    return 0;
}