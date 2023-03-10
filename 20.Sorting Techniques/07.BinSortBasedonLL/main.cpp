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
// Linked List node
class Node
{
public:
    int data;
    Node* next;
};

void Insert(Node **ptrBins, int idx)
{
    Node* temp = new Node;
    temp->data = idx;
    temp->next = nullptr;
    // ptrBins[idx] is head ptr
    if(ptrBins[idx] == nullptr)
        ptrBins[idx] = temp;
    else
    {
        Node* p = ptrBins[idx];
        while(p->next != nullptr)
            p = p->next;
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx)
{
    // ptrBins[idx] is head ptr
    Node* p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->data;
    delete p;
    return x;
}


void BinSort(int A[],int n)
{
    // O(n)
    int max = Max(A,n);
    // Create bins array
    Node **bins = new Node*[max+1];
    // Initialize bins array with nullptr
    for (int i = 0; i < max+1; i++)
        bins[i] = nullptr;
    // Update bins array values based on A values
    for (int i = 0; i < n; i++)
        Insert(bins,A[i]);
    // Update A with sorted elements
    int i = 0, j = 0;
    while (i < max+1)
    {
        while (bins[i] != nullptr)
            A[j++] = Delete(bins,i);
        i++;        
    }
    // Delete heap memory
    delete [] bins;
}

void print_arr(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main()
{
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    BinSort(A,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

