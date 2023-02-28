#include <iostream>
#include <vector>

using namespace std;

void Insert(vector<int>& vec, int key)
{
    int i = vec.size();
    vec.emplace_back(key);

    while (i > 0 && key > vec[i/2])
    {
        vec[i] = vec[i/2];
        i = i/2;
    }
    vec[i] = key;
}

void Swap(vector<int>& vec, int i, int j)
{
    int temp = vec.at(i);
    vec.at(i) = vec.at(j);
    vec.at(j) = temp;
}
int Delete(vector<int>& vec, int n)
{
    int temp,i,j,val;
    val = vec.front();
    vec.at(0) = vec.at(n); 
    vec.at(n) = val;
    i = 0; j = 2*i+1;

    while (j <= n-1)
    {
        // compare 2 child
        if (j < n-1 && vec.at(j+1) > vec.at(j))
            j = j+1;
        // compare child with parent
        if(vec.at(i) < vec.at(j))
        {
            Swap(vec,i,j);
            i = j;
            j = 2*i + 1;
        }
        else
            break;
    }
    return val;
}

void CreateHeap(vector<int>&vec, int A[], int n){
    // O(n log n)
    for (int i=0; i<n; i++)
        Insert(vec, A[i]);
}

void Heapify(vector<int>&vec, int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n/2)-1; i >=0 ; i--)
    {
        // Left child for current i
        int j = 2*i+1; 
        while (j < n-1)
        {
            // compare 2 child
            if (j < n-1 && vec[j+1] > vec[j])
                j = j+1;
            // compare child with parent
            if(vec[i] < vec[j])
            {
                Swap(vec,i,j);
                i = j;
                j = 2*i+1;
            }
            else
                break;
        }
        
    }
    
}


void print_vec(vector<int> vec, int n)
{
    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
        cout << vec.at(i) << " ";
    cout << endl;
}
int main()
{
    // vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    // print_vec(v,v.size());
    // v.reserve(15);
    // int b[] = {10, 20, 30, 25, 5, 40, 35};
    // vector<int> v;
    // CreateHeap(v,b,sizeof(b)/sizeof(b[0]));
    vector<int> v = {10, 20, 30, 25, 5, 40, 35};
    Heapify(v,v.size());
    print_vec(v,v.size());
    for(int i = v.size() - 1; i >= 0; i--)
        Delete(v,i);

    print_vec(v,v.size());


    return 0;
}