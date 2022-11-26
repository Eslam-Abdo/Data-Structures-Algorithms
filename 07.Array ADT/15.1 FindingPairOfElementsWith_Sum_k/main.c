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

/* finding pair of elements with sum of k in unsorted array method 1 */
void SumOfK_1(struct Array arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.length-1 ; i++)
        for (int j = i+1; j < arr.length; j++)
            if((arr.A[i] + arr.A[j]) == k)
                printf("%d + %d = %d\n", arr.A[i], arr.A[j], k);
        
}
/* finding pair of elements with sum of k in unsorted array method 2 using hashing */
void SumOfK_2(struct Array arr, int k)
{
    int l = Min(arr);
    int h = Max(arr);
    
    int hash_size = h+1;
    int *hash = (int*) malloc(hash_size * sizeof(int));
    for(int i=0 ; i<hash_size; i++)
        hash[i] = 0;
    
    for(int i=0 ; i<arr.length; i++)
    {
        if(hash[k-arr.A[i]] != 0)
            printf("%d + %d = %d\n", arr.A[i],k-arr.A[i] , k);
        hash[arr.A[i]]++;
    }
       
    free(hash);
}
int main()
{
    struct Array arr1 = {{6,3,8,10,16,7,5,2,9,14},12,10};


    Display(arr1);
    printf("\n");
    SumOfK_2(arr1,10);
   
    return 0;
}

