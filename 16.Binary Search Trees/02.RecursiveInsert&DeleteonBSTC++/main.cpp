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
            root = t;
            return t;
        }
        return RInsert(root,key);
    }
    Node* RInsert(Node* temp, int key);
    void Inorder(){Inorder(root);}
    void Inorder(Node* p);
    Node* Search(int key);
    Node* RSearch(int key){return RSearch(root,key);}
    Node* RSearch(Node* p, int key);
    Node* Delete(int key){return Delete(root,key);}
    Node* Delete(Node* p, int key);
    int Height(){return Height(root);}
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
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

int BST::Height(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y? x+1 : y+1;
}

Node* BST::InPre(Node* p)
{
    while(p != NULL && p->rchild != NULL)
        p = p->rchild;
    return p;
}

Node* BST::InSucc(Node* p)
{
    while(p != NULL && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node* BST::Delete(Node* p, int key)
{
    Node* q;
    if(p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(root == p)
            root = NULL;
        delete p;
        return NULL;

    }    
    if(key < p->data)
        p->lchild = Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }  
    }
    return p;
}

int main()
{
 
    BST bst;
 
    // Recursive insert
    bst.RInsert(10);
    bst.RInsert(5);
    bst.RInsert(20);
    bst.RInsert(8);
    bst.RInsert(30);
 
    // Inorder traversal
    bst.Inorder();
    cout << endl;
 
    // Iterative search
    Node* temp = bst.Search(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    // Recursive search
    temp = bst.RSearch(20);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    // Iterative insert
    bst.Insert(50);
    bst.Insert(70);
    bst.Insert(1);
    bst.Inorder();
    cout << endl;
    cout << "=========================" << endl;
 
    // Inorder predecessor and inorder successor
    BST bs;
    bs.Insert(5);
    bs.Insert(2);
    bs.Insert(8);
    bs.Insert(7);
    bs.Insert(9);
    bs.Insert(1);
 
    temp = bs.InPre(bs.getRoot());
    cout << "InPre: " << temp->data << endl;
 
    temp = bs.InSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;
 
    bs.Inorder();
    cout << endl;
 
    // Delete
    bs.Delete(7);
    bs.Inorder();
    cout << endl;

    return 0;
}