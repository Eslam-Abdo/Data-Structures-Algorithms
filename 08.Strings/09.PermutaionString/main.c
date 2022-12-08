#include <stdio.h>

/* method 1 */
void perm_1(char S[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;
    if(S[k]!='\0')
    {
        for(i=0; S[i]!='\0';i++)
            if(A[i] == 0)
            {
                A[i] = 1;
                Res[k] = S[i];
                perm_1(S,k+1);
                A[i] = 0;
            }
    }
    else
    {
        Res[k] = '\0';
        printf("%s\n",Res);
    }
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* method 2 */
void perm_2(char S[], int l, int h)
{
    int i;
    if( l == h)
    {
        printf("%s\n",S);
    }
    else
    {
       for(i=l; i<=h;i++)
        {
            swap(&S[l], &S[i]);
            perm_2(S,l+1,h);
            swap(&S[l], &S[i]);
        }
    }
}


int main()
{
    char str[] = "ABC";
    // perm_1(str,0);
    perm_2(str,0,2);


    return 0;
}
