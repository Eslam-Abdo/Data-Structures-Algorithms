#include <stdio.h>

/* solution 1 using recusion */
/* time complexity o(2^n) */
int fib1(int n)
{
    if(n<=1)
        return n;
    return fib1(n-2) + fib1(n-1);
}

/* solution 2 using recusion */
/* time complexity o(n) using memorization */
int F[10];
int fib2(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    if(F[n-2] == -1)
        F[n-2] = fib2(n-2);
    if(F[n-1] == -1)
        F[n-1] = fib2(n-1);
    F[n] = F[n-2] + F[n-1];
    return F[n-2] + F[n-1];
}

/* solution 3 using loops */
int fib3(int n)
{
    int t0 = 0, t1 = 1;
    int s = 0;
    if(n <= 1) 
        return n;
    for(int i=2; i<=n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}



int main()
{
    for(int i=0; i<10; i++)
        F[i] = -1;
    
    int r;
    // r = fib1(10);
    r = fib2(6);
    // r = fib3(10);
    printf("%d",r);    

    printf("\n");
    return 0;
}