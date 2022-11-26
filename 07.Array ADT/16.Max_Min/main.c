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
void Max_Min(struct Array arr)
{
    int max = arr.A[0];
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
        if(arr.A[i] < min)
            min = arr.A[i];
        else if(arr.A[i] > max)
            max = arr.A[i];

    printf("max: %d & min: %d\n",max,min);
}

int main()
{
    struct Array arr1 = {{5,8,3,9,6,2,10,7,-1,4},12,10};

    Max_Min(arr1);
    Display(arr1);
   
    return 0;
}

