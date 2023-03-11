#include <iostream>
using namespace std;


class HT_QuadraticProbe
{
private:
    int HSize = 10;
    int HT[10] = {0};
    int hash_fun(int key){return key % HSize;}
public:
    HT_QuadraticProbe(){}
    int QuadraticProbe(int key);
    void Insert(int key);
    int Search(int key);
    ~HT_QuadraticProbe(){}
};

int HT_QuadraticProbe::QuadraticProbe(int key)
{
    int index = hash_fun(key);
    int i = 0;
    while (HT[(index + i*i) % HSize] != 0)
        i++;
    return (index + i*i) % HSize;
}

void HT_QuadraticProbe::Insert(int key)
{
    int index = hash_fun(key);
    
    if(HT[index] != 0)
        index = QuadraticProbe(key);
    HT[index] = key;
}

int HT_QuadraticProbe::Search(int key)
{
    int index = hash_fun(key);
    int i = 0;
    while (HT[(index + i*i) % HSize] != key)
    {
        i++;
        if(HT[(index + i*i) % HSize] == 0)
            return -1;
    }
    if(HT[(index + i*i) % HSize] == key)
        return (index + i*i) % HSize;
    return -1;
}

int main()
{
    int A[] = {23, 43, 13, 27, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);

    HT_QuadraticProbe H;
    for (int i = 0; i < n; i++)
        H.Insert(A[i]);
    
    int index = H.Search(13);
    cout << "key found at: " << index << endl;
 
    index = H.Search(29);
    cout << "key found at: " << index << endl;
 

    return 0;
}
