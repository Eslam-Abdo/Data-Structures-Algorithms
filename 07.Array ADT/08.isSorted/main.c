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

int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}
void Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
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

int Sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];
    return total;
}
float Avg(struct Array arr)
{
    return (float) Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B = (int*) malloc(arr->length * sizeof(int));

    for(i=0,j=arr->length-1; j>=0; i++,j--)
        B[i] = arr->A[j]; 
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];

    free(B);
}

void Reverse_Swap(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--)
        swap(&arr->A[i], &arr->A[j]);

}

void Shift_left(struct Array *arr)
{
    int x = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        arr->A[i-1] = arr->A[i];
    arr->A[arr->length-1] = 0;    
}
void Rotate_left(struct Array *arr)
{
        int x = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        arr->A[i-1] = arr->A[i];
    arr->A[arr->length-1] = x; 
}


void InsertSort(struct Array *arr, int x)
{
    int i = arr->length -1;
    if(arr->length == arr->size)
        return;
    
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
        if(arr.A[i] > arr.A[i+1])
            return 0; 
    
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while (i<j)
    {
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    // struct Array Arr = {{2,3,5,10,15},10,5};
    struct Array Arr = {{2,-3,25,10,-15,-7},10,6};

    // InsertSort(&Arr,8);
    // printf("sort? %d\n",isSorted(Arr));
    Rearrange(&Arr);
    Display(Arr);

    return 0;
}

