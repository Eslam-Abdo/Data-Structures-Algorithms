#include <stdio.h>


int main()
{
    char s[] = "welcome";
    int i;
    for(i=0; s[i] != '\0'; i++);
    printf("length of \"%s\" is %d\n",s,i);

    return 0;
}