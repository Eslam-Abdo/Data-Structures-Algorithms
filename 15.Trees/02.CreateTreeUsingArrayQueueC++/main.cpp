#include <iostream>
#include "QueueCpp.h"

using namespace std; 

class Tree
{
private:
    Node* root;
public:
    Tree(){root = NULL;}
    ~Tree(){}
    void Create();
    void Preorder(){Preorder(root);}
    void Preorder(Node* p);
    void Inorder(){Inorder(root);}
    void Inorder(Node* p);
    void Postorder(){Postorder(root);}
    void Postorder(Node* p);
    void LevelOrder(){LevelOrder(root);}
    void LevelOrder(Node* p);
    int Height(){Height(root);}
    int Height(Node* p);
};

void Tree::Create()
{
    Node *t,*p;
    int x;
    Queue q(100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter Left child of " << p->data << ": ";
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter Right child of " << p->data << ": ";
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node* p)
{
    if(p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}


void Tree::LevelOrder(struct Node* p)
{
    Queue q(100);
    cout << p->data << " ";
    q.enqueue(p);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if(p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
    cout << endl;
}

int Tree::Height(struct Node* p)
{
    int x=0, y=0;
    if(p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return x > y? x+1 : y+1;
}


int main()
{
    Tree t;
    t.Create();

    cout<<"Preorder ";
    t.Preorder();
    cout<<endl;
    cout<<"Inorder ";
    t.Inorder();
    cout << endl;
    cout << "Postorder: ";
    t.Postorder();
    cout<<endl<<endl;

    return 0;
}