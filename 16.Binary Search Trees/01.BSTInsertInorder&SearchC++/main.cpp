#include <iostream>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST
{
private:
    Node* root;
public:
    BST(){root = NULL;}
    ~BST(){}
    Node* getRoot(){return root;}
    void Insert(int key);
    Node* RInsert(int key)
    {
        Node* t = NULL;
        if(root == NULL)
        {
            t = RInsert(root,key);
            t = root;
            return t;
        }
        return RInsert(root,key);
    }
    Node* RInsert(Node* temp, int key);
    void Inorder(Node* p);
    Node* Search(int key);
    Node* RSearch(int key){return RSearch(root,key);}
    Node* RSearch(Node* p, int key);
};

void BST::Insert(int key)
{
    Node* temp = root;
    Node* tail, *p;
    if(root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (temp != NULL)
    {
        tail = temp;
        if(key < temp->data)
            temp = temp->lchild;
        else if(key > temp->data)
            temp = temp->rchild;
        else
            return;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key < tail->data)
        tail->lchild = p;
    else
        tail->rchild = p;
}

Node* BST::RInsert(Node* temp, int key)
{
    Node *p = NULL;
    if(temp == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if(key < temp->data)
        temp->lchild = RInsert(temp->lchild,key);
    else
        temp->rchild = RInsert(temp->rchild,key);
    return temp;
}

void BST::Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node* BST::Search(int key)
{
    Node* temp = root;
    while (temp != NULL)
    {
        if(key < temp->data)
            temp = temp->lchild;
        else if(key > temp->data)
            temp = temp->rchild;
        else
            return temp;
    }
    return NULL;
}

Node* BST::RSearch(Node* p, int key)
{
    if(p == NULL)
        return NULL;
    if(p->data == key)
        return p;
    else if(key < p->data)
        return RSearch(p->lchild,key);
    else
        return RSearch(p->rchild,key);
}

int main()
{
 
    BST bst;
 
    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
    bst.RInsert(2);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;
 
    // Search
    Node* temp = bst.RSearch(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 

    return 0;
}