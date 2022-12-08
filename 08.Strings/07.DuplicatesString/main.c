#include <stdio.h>


void method_1(char *A)
{
    int count =0;
    int i,j;
    for(i = 0; A[i] != '\0'; i++)
    {
        if(A[i] != -1)
        {
            count = 1;
            for(j = i+1; A[j] != '\0'; j++)
                if(A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            if(count > 1)
                printf("char: %c duplicate: %d times\n",A[i],count);
        }
    }
}
/* using hash table */
void method_2(char* A)
{
    int H[26];
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
        H[A[i] - 'a']++;
    }
    for(i=0; i<26; i++)
    {
        if(H[i] > 1)
            printf("char: %c duplicate: %d times\n",i+'a',H[i]);       
    }
}

/* using bitwise */
void method_3(char* A)
{
    int h,x;
    int i;
    for(i=0; A[i] != '\0'; i++)
    {
        x = 1<<(A[i]-'a');
        if((x & h) > 0)
            printf("char: %c duplicate\n",A[i]);
        else
            h |= x;
    }
}

int main()
{
    char A[] = "finding";
    // method_1(A);
    // method_2(A);
    method_3(A);

    return 0;
}


