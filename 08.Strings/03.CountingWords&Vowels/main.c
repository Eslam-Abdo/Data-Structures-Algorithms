#include <stdio.h>


int main()
{
    char A[] = "How are   you";
    int i;
    int vcount = 0, ccount = 0;
    int words = 1;
    for(i=0; A[i] != '\0'; i++)
    {
        /* count vowels and consonents */
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'o' || A[i] == 'u' || A[i] == 'i' ||
            A[i] == 'A' || A[i] == 'E' || A[i] == 'O' || A[i] == 'U' || A[i] == 'I')
            vcount++;
        else if((A[i]>='A' && A[i] <='Z')||(A[i]>='a' && A[i] <='z'))
            ccount++;
        /* count words */
        if(A[i] == ' ' && A[i-1] != ' ')
            words++;
    }

    printf("\"%s\"\n"
            "num of words: %d\n"
            "num of vowels %d\n"
            "num of consonents: %d\n",
            A,words,vcount,ccount);

    return 0;
}