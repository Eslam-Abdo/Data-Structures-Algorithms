#include <stdio.h>


int fun1(int n)
{
    if(n > 0)
    {
        return fun1(n-1) + n;
    }
    return 0;
}


int fun2(int n)
{
    static int x = 0;
    if(n > 0)
    {
        x++;
        return fun2(n-1) + x;
    }
    return 0;
}

int y = 0;

int fun3(int n)
{
    if(n > 0)
    {
        y++;
        return fun3(n-1) + y;
    }
    return 0;
}
int main()
{
    int r;
    // r = fun1(5);
    // r = fun2(5);    
    r = fun3(5);    
    printf("%d\n",r);

    r = fun3(5);    
    printf("%d",r);

    printf("\n");
    return 0;
}