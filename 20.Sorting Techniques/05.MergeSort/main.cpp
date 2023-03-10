#include <iostream>

using namespace std;

void Merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid+1, k = low;
    int B[high+1];
    while (i <= mid && j <= high)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

   while (i <= mid)
        B[k++] = A[i++];

    while (j <= high)
        B[k++] = A[j++];
    
    /* Copy array B to A*/
    for (int i = low; i <= high; i++)
        A[i] = B[i];
    
}

void IterativeMergeSort(int A[],int n)
{
    // O(n * log(n) )
    int p;
    int low,mid,high;
    for(p = 2; p <= n; p*=2)
        for (int i = 0; (i+p-1) < n; i+=p)
        {
            low = i;
            high = i+p-1;
            mid = (high + low)/2;
            Merge(A,low,mid,high);
        }
    if(p/2 < n)
        Merge(A,0,p/2-1,n-1);
        
}

void RecursiveMergeSort(int A[], int low, int high)
{
    int mid;
    if(low < high)
    {
        // Calculate mid point
        mid = (high + low)/2;
        // Sort sub-lists
        RecursiveMergeSort(A,low,mid);
        RecursiveMergeSort(A,mid+1,high);
        // Merge sorted sub-lists
        Merge(A,low,mid,high);
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
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10, 4};
    int B[] = {2, 5, 8, 12, 3, 6, 7, 10, 4};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    IterativeMergeSort(A,n);
    printf("Iterative Merge Sort: \n");
    print_arr(A,n);

    RecursiveMergeSort(B,0,n-1);
    printf("Recursive Merge Sort: \n");
    print_arr(B,n);

    printf("\n");
    return 0;
}

