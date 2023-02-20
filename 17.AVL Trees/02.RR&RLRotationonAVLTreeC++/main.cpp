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
    void Inorder(){Inorder(root);}
    void Inorder(Node* p);
    Node* getRoot(){return root;}

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


int main()
{
    // RR Rotation
    AVL trr;
    trr.RInsert(10);
    trr.RInsert(20);
    trr.RInsert(30);
 
 
    trr.Inorder();
    cout << endl;
    cout << trr.getRoot()->data << endl;
 
    // RL Rotation
    AVL trl;
    trl.RInsert(20);
    trl.RInsert(50);
    trl.RInsert(30);
 
 
    trl.Inorder();
    cout << endl;
    cout << trl.getRoot()->data << endl;

    return 0;
}
