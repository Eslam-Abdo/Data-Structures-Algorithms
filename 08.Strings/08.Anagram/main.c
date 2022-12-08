#include <stdio.h>

void isAnagram(char *A, char *B)
{
    int H[26];
    int i,j;

    for ( i = 0; A[i]!='\0'; i++)
        H[A[i]-'a']++;
    
    for ( j = 0; B[j]!='\0'; j++)
    {
        H[B[j]-'a']--;
        if(H[B[j]-'a'] < 0)
        {
            printf("not Angram\n");
            return;
        }
    }
    if(i == j)
        printf("its Angram\n");
    else
        printf("its not Angram\n");

}


int main()
{
    /*
     * verbose & observe
     * decimal & medical
    */
//    isAnagram("decimal","medical");
   isAnagram("verbosee","observei");


    return 0;
}