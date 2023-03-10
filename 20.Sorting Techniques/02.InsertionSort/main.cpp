#include <iostream>

using namespace std;

void InsertioneSort(int A[],int n)
{
    // O(n^2)
    int j,x;
    for (int i = 1; i < n; i++)
    {
        j = i-1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
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
    int A[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    InsertioneSort(A,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

