#include <iostream>

using namespace std;

void Swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[],int n)
{
    // O(n^2)
    int j,k;
    for (int i = 0; i < n-1; i++)
    {
        for (j=k=i; j < n; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        Swap(&A[i],&A[k]);
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
    int A[] = {3, 7, 9, 10, 16, 25, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    SelectionSort(A,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

