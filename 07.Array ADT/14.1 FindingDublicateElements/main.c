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
/* finding duplicate element in sorted array method 1 */
void duplicate_1(struct Array arr)
{
    int last_duplicate = 0;
    for (int i = 0; i < arr.length-1 ; i++)
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != last_duplicate)
        {
            printf("%d\n", arr.A[i]);
            last_duplicate = arr.A[i];
        }
}
/* finding duplicate element in sorted array and duplicate numbers method 1 */
void N_duplicate_1(struct Array arr)
{
    int j = 0;
    for (int i = 0; i < arr.length-1 ; i++)
        if(arr.A[i] == arr.A[i+1])
        {
            j = i+1;
            while(arr.A[j] == arr.A[i])j++;
            printf("%d is appearing %d times\n", arr.A[i],j-i);
            i = j-1;
        }
}

int main()
{
    struct Array arr1 = {{3,6,8,8,10,12,15,15,15,20},12,10};


    Display(arr1);
    printf("duplicate element:\n");
    // duplicate_1(arr1);
    N_duplicate_1(arr1);
   
    return 0;
}

