#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[12];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements are\n");

    for(int i=0; i<arr.length; i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}

/* finding multiple missing element in array method 1 */
void method_1(struct Array arr)
{
    int diff = arr.A[0];
    for(int i=0 ; i<arr.length; i++)
        if((arr.A[i] - i) != diff)
            while(diff < (arr.A[i] - i))
            {
                printf("%d\n",i+diff);
                diff++;
            }
}

int main()
{
    struct Array arr1 = {{6,7,8,9,11,12,15,16,17,18,19},12,11};


    Display(arr1);
    printf("missing element:\n");
    method_1(arr1);
    
   
    return 0;
}

