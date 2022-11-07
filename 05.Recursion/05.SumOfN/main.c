#include <stdio.h>

/* solution 1 using recusion */
int sum1(int n)
{
    if(n==0)
        return 0;
    return sum1(n-1) + n;
}


/* solution 2 using loops */
int sum2(int n)
{
    int s = 0;
    for(int i=1; i<=n; i++)
        s += i;
    return s;
}

/* solution 3 using mathmatics */
int sum3(int n)
{
    return n*(n+1)/2;
}

int main()
{
    int r;
    // r = sum1(5);
    // r = sum2(5);
    r = sum3(5);
    printf("%d",r);    

    printf("\n");
    return 0;
}