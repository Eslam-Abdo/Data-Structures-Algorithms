#include <stdio.h>


int main()
{
    char A[] = "IslAm";
    int i;
    /* togale uppear and lower case */
    for(i=0; A[i] != '\0'; i++)
    {
        if(A[i]>='A' && A[i] <='Z')
            A[i] += 32;
        else if(A[i]>='a' && A[i] <='z')
            A[i] -= 32;
    }
    printf("string is \"%s\" \n",A);

    return 0;
}