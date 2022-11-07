#include <stdio.h>

/* solution 1 using recusion */
int fact1(int n)
{
    if(n==0)
        return 1;
    return fact1(n-1) * n;
}


/* solution 2 using loops */
int fact2(int n)
{
    int s = 1;
    for(int i=1; i<=n; i++)
        s *= i;
    return s;
}

int main()
{
    int r;
    // r = fact1(5);
    r = fact2(5);
    printf("%d",r);    

    printf("\n");
    return 0;
}