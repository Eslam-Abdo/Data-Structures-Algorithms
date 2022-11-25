#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
    
    ~Array()
    {
        delete []A;
    }
};

template <class T>
void Array<T>::Display()
{
    cout << "\nElements are:\n";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    if(index >= 0 && index <= length)
    {
        for (int i = length-1; i >= index; i--)
            A[i+1] = A[i];
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T x = 0;
    if(index >= 0 && index < length)
    {
        x = A[index]; 
        for(int i=index; i<length; i++)
            A[i] = A[i+1];
        A[length-1] = 0;
        length--;
    }
    return x;
}

int main()
{
    Array<char> arr(10);

    arr.Insert(0,'A');
    arr.Insert(1,'f');
    arr.Insert(2,'L');
    arr.Insert(0,'e');

    arr.Display();

    cout << arr.Delete(2) << endl;
    arr.Display();

    return 0;
}