#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *p, *q;

    p = (int*) malloc(5 * sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    q = (int*) malloc(10 * sizeof(int));

    /* print static array */
    for(int i=0; i<5; i++)
        q[i] = p[i];

    free(p);
    p = q;
    q = NULL;
    /* print dynamic array */
    for(int i=0; i<5; i++)
        printf("%d\t",p[i]);

    printf("\n");

    return 0;
}