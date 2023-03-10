#include <iostream>

using namespace std;

void Swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int low, int high)
{
    int pivote = A[low];
    int i = low, j = high;
    do
    {
        // Increment i as long as elements are smaller/equal to pivot
        do{i++;}while(A[i] <= pivote);
        // Decrement j as long as elements are larger than pivot
        do{j--;}while(A[j] > pivote);
        if(i < j)
            Swap(&A[i],&A[j]);
    } while (i < j);

    Swap(&A[low],&A[j]);

    return j;
}

void QuickSort(int A[], int low, int high)
{
    int j;
    if(low < high)
    {
        j = Partition(A,low,high);
        QuickSort(A,low,j);
        QuickSort(A,j+1,high);
    }
}

void print_arr(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: %d\n",n);
    print_arr(A,n);

    QuickSort(A,0,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

