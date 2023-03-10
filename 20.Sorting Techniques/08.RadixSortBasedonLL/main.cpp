#include <iostream>
#include <cmath>

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

void Insert(Node **ptrBins, int value, int idx)
{
    Node* temp = new Node;
    temp->data = value;
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

int CountDigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x/10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n)
{
    for (int i = 0; i < n; i++)
        p[i] = nullptr;
}

int getBinIndex(int x, int idx)
{
    return (int)(x/pow(10, idx)) % 10;
}

void RadixSort(int A[],int n)
{
    // O(n)
    int max = Max(A,n);
    int nPass = CountDigits(max);
    int digit_num = 10; 
    // Create bins array
    Node **bins = new Node*[digit_num];
    // Initialize bins array with nullptr
    initializeBins(bins,digit_num); 

    // Update bins and A for nPass times
    for(int pass=0; pass < nPass; pass++)
    {
        // Update bins array values based on A values
        for (int i = 0; i < n; i++)
        {
            int binIdx = getBinIndex(A[i],pass);
            Insert(bins,A[i],binIdx);
        }
        // Update A with sorted elements
        int i = 0, j = 0;
        while (i < digit_num)
        {
            while (bins[i] != nullptr)
                A[j++] = Delete(bins,i);
            i++;        
        }
        // Initialize bins with nullptr again
        initializeBins(bins,digit_num);
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
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);

    printf("UnSorted Arr: \n");
    print_arr(A,n);

    RadixSort(A,n);
    printf("Sorted Arr: \n");
    print_arr(A,n);

    printf("\n");
    return 0;
}

