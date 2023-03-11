#include <iostream>
using namespace std;


class HT_LinearProbe
{
private:
    int HSize = 10;
    int HT[10] = {0};
    int hash_fun(int key){return key % HSize;}
public:
    HT_LinearProbe(){}
    int LinearProbe(int key);
    void Insert(int key);
    int Search(int key);
    ~HT_LinearProbe(){}
};

int HT_LinearProbe::LinearProbe(int key)
{
    int index = hash_fun(key);
    int i = 0;
    while (HT[(index + i) % HSize] != 0)
        i++;
    return (index + i) % HSize;
}

void HT_LinearProbe::Insert(int key)
{
    int index = hash_fun(key);
    
    if(HT[index] != 0)
        index = LinearProbe(key);
    HT[index] = key;
}

int HT_LinearProbe::Search(int key)
{
    int index = hash_fun(key);
    int i = 0;
    while (HT[(index + i) % HSize] != key)
    {
        i++;
        if(HT[(index + i) % HSize] == 0)
            return -1;
    }
    if(HT[(index + i) % HSize] == key)
        return (index + i) % HSize;
    return -1;
}

int main()
{
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);

    HT_LinearProbe H;
    for (int i = 0; i < n; i++)
        H.Insert(A[i]);
    
    int index = H.Search(25);
    cout << "key found at: " << index << endl;
 
    index = H.Search(35);
    cout << "key found at: " << index << endl;
 

    return 0;
}
