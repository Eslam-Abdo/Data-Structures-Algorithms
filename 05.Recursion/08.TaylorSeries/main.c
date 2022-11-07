#include <stdio.h>

/* solution 1 using recusion : Taylor Series using Static variables */
double exp_1(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r = exp_1(x, n-1);
        p *= x;
        f *= n;
        return r + p/f;
    }
}
/* solution 2 using loops : Taylor Serie Iterative */
double exp_2(int x, int n)
{
    double p = 1, f = 1;
    double r = 1;
    for(int i=1; i<=n; i++)
    {
        p *= x;
        f *= i;
        r += p/f;
    }
    return r;
}
/* solution 3 using recusion : Taylor Series using Horner’s Rule */
double exp_3(int x, int n)
{
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + x*s/n;
    return exp_3(x,n-1);  
}

/* solution 4 using loops : Taylor Series Iterative using Horner’s Rule */
double exp_4(int x, int n)
{
    double s = 1;
    for(; n>0; n--)
        s = 1 + x*s/n;
    return s;
}

int main()
{
    double r;
    // r = exp_1(3,10);
    // r = exp_2(3,10);    
    // r = exp_3(1,10);
    r = exp_4(3,10);
    printf("%lf",r);    

    printf("\n");
    return 0;
}