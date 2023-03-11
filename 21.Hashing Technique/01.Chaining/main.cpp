#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class HT_Chaining
{
private:
    Node** HT;
    int HLength = 10;
    int hash_fun(int key){return key % 10;}
public:
    HT_Chaining();
    void Insert(int key);
    int Search(int key);
    ~HT_Chaining();
};

HT_Chaining::HT_Chaining()
{
    HT = new Node*[HLength];
    for(int i=0; i < HLength; i++)
        HT[i] = nullptr; 
}

void HT_Chaining::Insert(int key)
{
    int Index = hash_fun(key);

    Node* temp = new Node;
    temp->data = key;
    temp->next = nullptr;
	// Case: No nodes in the linked list
    if(HT[Index] == nullptr)
        HT[Index] = temp;
    else
    {
        Node* p = HT[Index];
        Node* q = p;
		// Traverse to find insert position
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }
		// Case: insert position is first
        if(q == HT[Index])
        {
            temp->next = HT[Index];
            HT[Index] = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }    
}

int HT_Chaining::Search(int key)
{
    int Index = hash_fun(key);
    Node* p = HT[Index];
    while(p)
    {
        if(p->data == key)
            return p->data;
        p = p->next;
    }
    return -1;
}

HT_Chaining::~HT_Chaining()
{
    for (int i = 0; i < HLength; i++)
    {
        Node* p = HT[i];
        while (HT[i])
        {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete [] HT;
}

int main()
{
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
    HT_Chaining H;
    for (int i = 0; i < n; i++)
        H.Insert(A[i]);

    cout << "Successful Search" << endl;
	int key = 6;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

    return 0;
}

