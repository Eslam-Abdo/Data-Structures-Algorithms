#include <stdio.h>

/* solution 1 using recusion */
int power1(int m, int n)
{
    if(n==0)
        return 1;
    return power1(m, n-1) * m;
}

/* solution 2 using recusion by reduce steps */
int power2(int m, int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return power2(m*m, n/2);
    return m*power2(m*m, (n-1)/2);
}

/* solution 3 using loops */
int power3(int m, int n)
{
    int s = 1;
    for(int i=1; i<=n; i++)
        s *= m;
    return s;
}

int main()
{
    int r;
    // r = power1(3,4);
    // r = power2(2,9);
    r = power3(4,3);
    printf("%d",r);    

    printf("\n");
    return 0;
}