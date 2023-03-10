#include <iostream>

using namespace std;

void InsertioneSort(int A[],int n)
{
    // O(n*log(n))
    int j,temp;
    for (int gap = n/2; gap >= 1; gap/=2)
    {
        for (int i=gap; i < n; i++)
        {
            temp = A[i];
            j = i-gap;
            while (j > -1 && A[j] > temp)
            {
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
        }
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
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    InsertioneSort(A,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

