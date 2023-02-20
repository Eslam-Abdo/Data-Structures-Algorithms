#include <iostream>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL
{
private:
    Node* root;
public:
    AVL(){root = NULL;}
    // Helper methods for inserting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);

    Node* RInsert(int key);
    Node* RInsert(Node* temp, int key);
    Node* Delete(int key){return Delete(root,key);}
    Node* Delete(Node* p, int key);

    void Inorder(){Inorder(root);}
    void Inorder(Node* p);
    Node* getRoot(){return root;}
    Node* InPre(Node* p);
    Node* InSucc(Node* p);

};

int AVL::NodeHeight(Node* p)
{
    int hl,hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return (hl > hr) ? hl+1 : hr+1;
}

int AVL::BalanceFactor(Node* p)
{
    int hl,hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}

Node* AVL::LLRotation(Node*p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if(root == p)
        root = pl;
    return pl;
}


Node* AVL::RRRotation(Node*p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(root == p)
        root = pr;
    return pr;
}

Node* AVL::LRRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    if(root == p)
        root = plr;
    return plr;
}

Node* AVL::RLRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
    if(root == p)
        root = prl;
    return prl;
}

Node* AVL::RInsert(int key)
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

Node* AVL::RInsert(Node* temp, int key)
{
    Node *p = NULL;
    if(temp == NULL)
    {
        p = new Node;
        p->data = key;
        p->height = 1;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if(key < temp->data)
        temp->lchild = RInsert(temp->lchild,key);
    else
        temp->rchild = RInsert(temp->rchild,key);

    temp->height = NodeHeight(temp);

    if(BalanceFactor(temp) == 2 && BalanceFactor(temp->lchild) == 1)
        return LLRotation(temp);
    else if(BalanceFactor(temp) == 2 && BalanceFactor(temp->lchild) == -1)
        return LRRotation(temp);
    else if(BalanceFactor(temp) == -2 && BalanceFactor(temp->rchild) == -1)
        return RRRotation(temp);
    else if(BalanceFactor(temp) == -2 && BalanceFactor(temp->rchild) == 1)
        return RLRotation(temp);

    return temp;
}

void AVL::Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}


Node* AVL::InPre(Node* p)
{
    while(p != NULL && p->rchild != NULL)
        p = p->rchild;
    return p;
}

Node* AVL::InSucc(Node* p)
{
    while(p != NULL && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node* AVL::Delete(Node* p, int key)
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
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild))
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

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) // L1 Rotation
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) // L-1 Rotation
        return LRRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) // L0 Rotation
        return LLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) // R-1 Rotation
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) // R1 Rotation
        return RLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0) // R0 Rotation
        return RRRotation(p);

    return p;
}

int main()
{
    AVL tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.RInsert(A[i]);
    }
 
    tree.Inorder();
    cout << endl;
 
    tree.Delete(28);
   
    tree.Inorder();
    cout << endl;

    return 0;
}
