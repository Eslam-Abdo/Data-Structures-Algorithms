#include <stdio.h>

void ComparingString(char *A,char *B)
{
    int i;
    for(i=0; A[i]!='\0' && B[i]!='\0'; i++)
    {
        if(!((A[i]>='A' && A[i] <='Z' && B[i]>='A' && B[i] <='Z') ||
            (A[i]>='a' && A[i] <='z' && B[i]>='a' && B[i] <='z')))
        {
            if(A[i]>='A' && A[i] <='Z')
                A[i] += 32;
            else if(A[i]>='a' && A[i] <='z')
                A[i] -= 32;
        }
        if(A[i] != B[i])
            break;
    }
    if(A[i] == B[i])
        printf("equal\n");
    else if(A[i] < B[i])
        printf("smaller\n");
    else
        printf("greater\n");
}

void isPalindrome(char *A)
{
    int i,j;
    for (j = 0; A[j]!='\0'; j++);
    j--;

    for (i = 0; i<j; j--,i++)
        if(A[i] != A[j])
        {
            printf("not palindrome\n");
            return;
        }
    printf("palindrome\n");   
}
 

int main()
{
    /* comparing string */
    // char A[] = "prInter";
    // char B[] = "Printer";
    // ComparingString(A,B);

    /* palinding string */
    char C[] = "madam";
    isPalindrome(C);
    
    return 0;
}
