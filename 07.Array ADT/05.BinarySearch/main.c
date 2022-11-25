#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
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
void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;        
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x; 
    }
    return 0;
}

int LinearSearch(struct Array arr, int key)
{
    for(int i=0; i<arr.length; i++)
        if(key == arr.A[i])
            return i;
    return -1;
}
/* improve methods */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* 1. transportion */
int Improve_LinearSearch_1(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    return -1;
}
/* 2. move to head/front */
int Improve_LinearSearch_2(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    return -1;
}


int BinarySearch(struct Array arr, int key)
{
    int l,h,mid;
    l = 0;
    h = arr.length - 1;

    while (l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(int a[],int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h,key);
    }

    return -1;
}
int main()
{
    struct Array Arr = {{2,3,4,5,6},10,5};
    int key = 3;

    // printf("binary search \tkey:%d \tindex:%d\n",key ,BinarySearch(Arr,key));
    printf("binary search \tkey:%d \tindex:%d\n",key ,RBinSearch(Arr.A,0,Arr.length-1,key));

    Display(Arr);

    return 0;
}

