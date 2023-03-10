#include <iostream>

using namespace std;

int Max(int A[], int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
        if(A[i] > max)
            max = A[i];
    return max;
}

void CountSort(int A[],int n)
{
    // O(n)
    int max = Max(A,n);
    // Create count array
    int *count = new int[max+1];
    // Initialize count array with 0
    for (int i = 0; i < max+1; i++)
        count[i] = 0;
    // Update count array values based on A values
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    int i = 0, j = 0;
    while (j < max+1)
    {
        if(count[j] > 0)
        {
            A[i++] = j;
            count[j]--;
        }
        else
            j++;
    }
    // Delete heap memory
    delete [] count;
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

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    CountSort(A,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

