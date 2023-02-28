#include <stdio.h>


void Insert(int A[], int n)
{
    int i = n;
    int temp = A[i];
    while (i > 0 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int Delete(int A[], int n)
{
    int temp,i,j,val;
    val = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1; j = 2*i; 
    while (j <= n-1)
    {
        // compare 2 child
        if (j < n-1 && A[j+1] > A[j])
            j = j+1;
        // compare child with parent
        if(A[i] < A[j])
        {
            Swap(A,i,j);
            i = j;
            j = 2*i;
        }
        else
            break;
    }
    return val;
}

void CreateHeap(int A[], int n){
    // O(n log n)
    for (int i=0; i<n; i++)
        Insert(A, i);
}

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n/2)-1; i >=0 ; i--)
    {
        // Left child for current i
        int j = 2*i+1; 
        while (j < n-1)
        {
            // compare 2 child
            if (j < n-1 && A[j+1] > A[j])
                j = j+1;
            // compare child with parent
            if(A[i] < A[j])
            {
                Swap(A,i,j);
                i = j;
                j = 2*i+1;
            }
            else
                break;
        }
        
    }
    
}

void print_heap(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");
}
int main()
{
    int H[] = {10, 20, 30, 25, 5, 40, 35};
    int H_size = sizeof(H)/sizeof(H[0]);
    // CreateHeap(H, H_size);
    Heapify(H,H_size);
    print_heap(H,H_size);
    for(int i = H_size - 1; i >= 0; i--)
        Delete(H,i);

    print_heap(H,H_size);


    printf("\n");
    return 0;
}


