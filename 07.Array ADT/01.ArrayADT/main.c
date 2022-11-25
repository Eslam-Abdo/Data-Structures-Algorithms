#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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

int main()
{
    struct Array Arr;
    int n;
    printf("Enter size of an array");
    scanf("%d",&Arr.size);

    Arr.A = (int*) malloc(Arr.size*sizeof(int));
    Arr.length = 0;

    printf("Enter number of numbers");
    scanf("%d",&n);

    printf("Enter all elements\n");

    for(int i=0; i<n; i++)
        scanf("%d",&Arr.A[i]);

    Arr.length = n;
    Display(Arr);

    return 0;
}

