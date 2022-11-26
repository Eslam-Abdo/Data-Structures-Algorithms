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
/* finding single missing element in array method 1 */
int method_1(struct Array arr)
{
    int sum = 0;
    int s = arr.A[arr.length-1]* (arr.A[arr.length-1] + 1)/2;

    for(int i=0 ; i<arr.length; i++)
        sum += arr.A[i];
    return s-sum;
}
/* finding single missing element in array method 2 */
int method_2(struct Array arr)
{
    int diff = arr.A[0];
    for(int i=0 ; i<arr.length; i++)
        if((arr.A[i] - i) != diff)
            return diff + i;
    return -1;
}

int main()
{
    struct Array arr1 = {{1,2,3,4,5,7,8,9,10},12,9};
    struct Array arr2 = {{6,7,8,9,11,12,13,14,15},12,9};


    Display(arr1);
    printf("missing element: %d\n",method_1(arr1));
    
    Display(arr2);
    printf("missing element: %d\n",method_2(arr2));

    return 0;
}

