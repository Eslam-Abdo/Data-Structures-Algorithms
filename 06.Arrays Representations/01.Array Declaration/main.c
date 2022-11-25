#include <stdio.h>


int main()
{
    // int A[5];
    int B[5] = {1,2,3,4,5};
    // int C[10] = {2,4,6};
    // int D[5] = {0};
    // int E[] = {1,2,3,4,5,6};
    // int F[8] = {3}; /* 3 0 0 0 0 0 0 0 */

    /* print address of A elements*/
    for(int i=0; i<5; i++)
        printf("%u : %d\n",&B[i],i[B]);

    return 0;
}