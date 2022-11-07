#include <stdio.h>


/* help function */
int fact1(int n)
{
    if(n==0)
        return 1;
    return fact1(n-1) * n;
}
int fact2(int n)
{
    int s = 1;
    for(int i=1; i<=n; i++)
        s *= i;
    return s;
}
/* solution 1 using facturial */
int nCr_1(int n, int r)
{
    int num ,dum;
    num = fact1(n);
    dum = fact1(r) * fact1(n-r);
    return num/dum;
}
/* solution 2 using loops */
int nCr_2(int n, int r)
{
    int num ,dum;
    num = fact2(n);
    dum = fact2(r) * fact2(n-r);
    return num/dum;
}
/* solution 3 using recusion: pascal's triangle */
int nCr_3(int n, int r)
{
    if(r==0 || r==n)
        return 1;
    return nCr_3(n-1,r-1) + nCr_3(n-1,r);
}


int main()
{
    int r;
    // r = nCr_1(5,0);
    // r = nCr_2(4,2);
    r = nCr_3(5,3);
    printf("%d",r);    

    printf("\n");
    return 0;
}