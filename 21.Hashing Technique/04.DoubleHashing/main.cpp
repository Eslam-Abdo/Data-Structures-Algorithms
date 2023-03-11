#include <iostream>
using namespace std;


class HT_DoubleHashing
{
private:
    int HSize = 10;
    int Prime = 7;
    int HT[10] = {0};
    int PrimeHash(int key){return Prime - (key % Prime);}
    int hash_fun(int key){return key % HSize;}
public:
    HT_DoubleHashing(){}
    int DoubleHashing(int key);
    void Insert(int key);
    int Search(int key);
    ~HT_DoubleHashing(){}
};

int HT_DoubleHashing::DoubleHashing(int key)
{
    int index = hash_fun(key);
    int prime_index = PrimeHash(key);
    int i = 0;
    while (HT[(index + i * prime_index) % HSize] != 0)
        i++;
    return (index + i * prime_index) % HSize;
}

void HT_DoubleHashing::Insert(int key)
{
    int index = hash_fun(key);
    
    if(HT[index] != 0)
        index = DoubleHashing(key);
    HT[index] = key;
}

int HT_DoubleHashing::Search(int key)
{
    int index = hash_fun(key);
    int prime_index = PrimeHash(key);

    int i = 0;
    while (HT[(index + i * prime_index) % HSize] != key)
    {
        i++;
        if(HT[(index + i * prime_index) % HSize] == 0)
            return -1;
    }
    if(HT[(index + i * prime_index) % HSize] == key)
        return (index + i * prime_index) % HSize;
    return -1;
}

int main()
{
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);

    HT_DoubleHashing H;
    for (int i = 0; i < n; i++)
        H.Insert(A[i]);
    
    int index = H.Search(25);
    cout << "key found at: " << index << endl;
 
    index = H.Search(35);
    cout << "key found at: " << index << endl;
 

    return 0;
}
