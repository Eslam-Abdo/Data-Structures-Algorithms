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
int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
        if(max < arr.A[i])
            max = arr.A[i];
    return max;
}
int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
        if(min > arr.A[i])
            min = arr.A[i];
    return min;
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
/* finding multiple missing element in unsorted array method 2 */
void method_2(struct Array arr)
{
    int l = Min(arr);
    int h = Max(arr);
    int diff = l;
    int hash_size = h-l;
    int *hash = (int*) malloc(hash_size * sizeof(int));
    for(int i=0 ; i<hash_size; i++)
        hash[i] = 0;
    
    for(int i=0 ; i<arr.length; i++)
        hash[arr.A[i] - diff]++;

    for(int i=0 ; i<hash_size; i++)
        if(hash[i] == 0)
            printf("%d\n",i+diff);
    free(hash);
}
int main()
{
    struct Array arr1 = {{3,7,4,9,12,6,1,11,2,10},12,10};


    Display(arr1);
    printf("missing element:\n");
    method_2(arr1);
    
   
    return 0;
}

