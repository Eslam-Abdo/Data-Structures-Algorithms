#include <iostream>

using namespace std;

class Array
{
    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);

    public:
        Array()
        {
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new int[size];
        }

        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int  Delete(int index);
        int  LinearSearch(int key);
        int  Improve_LinearSearch_1(int key);
        int  Improve_LinearSearch_2(int key);
        int  BinarySearch(int key);
        // int  RBinSearch(int a[],int l, int h, int key);
        int  Get(int index);
        void Set(int index, int x);
        int  Max();
        int  Min();
        int  Sum();
        float Avg();
        void Reverse();
        void Reverse_Swap();
        void Shift_left();
        void Rotate_left();
        void InsertSort(int x);
        int  isSorted();
        void Rearrange();
        Array* Marge(Array arr2);
        Array* Union(Array arr2);
        Array* Intersection(Array arr2);
        Array* Difference(Array arr2);

        ~Array()
        {
            delete [] A;
        }
};

void Array::Display()
{
    cout << "\nElements are\n";

    for(int i=0; i<length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::Append(int x)
{
    if(length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    if(index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;        
    }
}

int Array::Delete(int index)
{
    int x = 0;
    if(index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
        return x; 
    }
    return 0;
}

int Array::LinearSearch(int key)
{
    for(int i=0; i<length; i++)
        if(key == A[i])
            return i;
    return -1;
}
/* improve methods */
void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* 1. transportion */
int Array::Improve_LinearSearch_1(int key)
{
    for(int i=0; i<length; i++)
        if(key == A[i])
        {
            swap(&A[i], &A[i-1]);
            return i;
        }
    return -1;
}
/* 2. move to head/front */
int Array::Improve_LinearSearch_2(int key)
{
    for(int i=0; i<length; i++)
        if(key == A[i])
        {
            swap(&A[i], &A[0]);
            return i;
        }
    return -1;
}


int Array::BinarySearch(int key)
{
    int l,h,mid;
    l = 0;
    h = length - 1;

    while (l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
#if 0
int Array::RBinSearch(int a[],int l, int h, int key)
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
#endif
int Array::Get(int index)
{
    if(index >= 0 && index < length)
        return A[index];
    return -1;
}
void Array::Set(int index, int x)
{
    if(index >= 0 && index < length)
        A[index] = x;
}
int Array::Max()
{
    int max = A[0];
    for(int i=1; i<length; i++)
        if(max < A[i])
            max = A[i];
    return max;
}
int Array::Min()
{
    int min = A[0];
    for(int i=1; i<length; i++)
        if(min > A[i])
            min = A[i];
    return min;
}

int Array::Sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
        total += A[i];
    return total;
}
float Array::Avg()
{
    return (float) Sum()/length;
}

void Array::Reverse()
{
    int *B;
    int i,j;
    B = new int[length];

    for(i=0,j=length-1; j>=0; i++,j--)
        B[i] = A[j]; 
    for (i = 0; i < length; i++)
        A[i] = B[i];

    free(B);
}

void Array::Reverse_Swap()
{
    int i,j;
    for(i=0,j=length-1; i<j; i++,j--)
        swap(&A[i], &A[j]);

}

void Array::Shift_left()
{
    int x = A[0];
    for (int i = 1; i < length; i++)
        A[i-1] = A[i];
    A[length-1] = 0;    
}
void Array::Rotate_left()
{
        int x = A[0];
    for (int i = 1; i < length; i++)
        A[i-1] = A[i];
    A[length-1] = x; 
}


void Array::InsertSort(int x)
{
    int i = length -1;
    if(length == size)
        return;
    
    while (i>=0 && A[i]>x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}
int Array::isSorted()
{
    for (int i = 0; i < length-1; i++)
        if(A[i] > A[i+1])
            return 0; 
    
    return 1;
}

void Array::Rearrange()
{
    int i = 0;
    int j = length-1;
    while (i<j)
    {
        while(A[i] < 0)i++;
        while(A[j] >= 0)j--;
        if(i<j)swap(&A[i],&A[j]);
    }
}

Array* Array::Marge(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length + arr2.length);
    
    while(i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for(;i < length; i++)
        arr3->A[k++] = A[i];
    for(;j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    
    arr3->length = length + arr2.length;
    return arr3;
}

Array* Array::Union(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length + arr2.length);
    
    while(i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if(arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else if(A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(;i < length; i++)
        arr3->A[k++] = A[i];
    for(;j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    
    arr3->length = k;
    return arr3;
}

Array* Array::Intersection(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length + arr2.length);
    
    while(i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            i++;
        else if(arr2.A[j] < A[i])
            j++;
        else if(A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

Array* Array::Difference(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length + arr2.length);

    while(i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if(arr2.A[j] < A[i])
            j++;
        else if(A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
    }
    for(;i < length; i++)
        arr3->A[k++] = A[i];
    
    arr3->length = k;
    return arr3;
}

int main()
{
    Array *arr1;
    int ch,sz;
    int x,index;

    cout << "Enter size of an array ";
    cin >> sz;
    arr1 = new Array(sz);
    do{
        cout << "\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            /* 1. Insert */
            cout << "Enter an element and index ";
            cin >> x >> index;
            arr1->Insert(index,x);
            break;
        case 2:
            /* 2. Delete */
            cout << "Enter index ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted element is " << x << endl;
            break;
        case 3:
            /* 3. Search */
            cout << "Enter element to search ";
            cin >> x;
            index = arr1->LinearSearch(x);
            cout << "Element index " << index << endl;
            break;
        case 4:
            /* 4. Sum */
            cout << "Sum is " << arr1->Sum() << endl;
            break;
        case 5:
            /* 5. Display */
            arr1->Display();
            break;
        }
    }while(ch<6);
    
    cout << "Good Bye :D\n";
    return 0;
}

