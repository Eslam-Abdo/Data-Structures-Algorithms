#include <stdio.h>


void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    char A[] = "python";
    char B[7];
    int j,y,i;

    for (j = 0; A[j]!='\0'; j++);
    j--;
    y=j;
    
    /* reversing method 1 */
    for (i = 0; j>=0; j--,i++)
        B[i] = A[j];
    printf("method_1: \"%s\"\n",B);    
    B[i] = '\0';

    /* reversing method 2 */
    for (i = 0; i<y; y--,i++)
        swap(&A[i],&A[y]);    
    printf("method_2: \"%s\"\n",A);    

    return 0;
}