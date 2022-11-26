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

/* finding duplicate element in sorted array and duplicate numbers method 1 */
void N_duplicate_1(struct Array arr)
{
    int count = 0;
    for (int i = 0; i < arr.length-1 ; i++)
    {
        count = 1;
        if(arr.A[i] != -1)
        {
            for (int j = i+1; j < arr.length; j++)
                if(arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            if(count > 1)
                printf("%d is appearing %d times\n", arr.A[i], count);

        }
    }
        
}
/* finding duplicate element in unsorted array method 2 using hashing */
void N_duplicate_2(struct Array arr)
{
    int l = Min(arr);
    int h = Max(arr);
    int diff = l;
    int hash_size = h-l+1;
    int *hash = (int*) malloc(hash_size * sizeof(int));
    for(int i=0 ; i<hash_size; i++)
        hash[i] = 0;
    
    for(int i=0 ; i<arr.length; i++)
        hash[arr.A[i] - diff]++;

    for(int i=0 ; i<=hash_size; i++)
        if(hash[i] > 1)
            printf("%d is appearing %d times\n", i+diff,hash[i]);
            
    free(hash);
}
int main()
{
    struct Array arr1 = {{8,3,6,4,6,5,6,8,2,7},12,10};


    Display(arr1);
    printf("duplicate element:\n");
    // N_duplicate_1(arr1);
    N_duplicate_2(arr1);
   
    return 0;
}

