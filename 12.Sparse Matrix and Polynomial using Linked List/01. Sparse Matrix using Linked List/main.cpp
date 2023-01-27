#include <iostream>

using namespace std;

class Element
{
public:
    int col;
    int data;
    Element* next;
};

class SparseLL
{
private:
    int m,n,num;
    Element ** matrix;
public:
    SparseLL()
    {
        cout << "Enter Dimentions: ";
        cin >> m >> n;
        cout << "Number of non-zero: ";
        cin >> num;
        matrix = new Element*[m];
    }
    SparseLL(int m, int n,int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        matrix = new Element*[this->m];
    }
    ~SparseLL(){delete [] matrix;}
    void Create();
    void Display();
    SparseLL add(SparseLL *p);
};
void SparseLL::Create()
{
    int index, col, data;
    Element* temp,*last;
    cout << "Enter non-zero elements"<< endl;
    for (int i = 0; i < num; i++)
    {
        cin >> index >> col >> data;
        temp = new Element;
        temp->col = col;
        temp->data = data;
        temp->next = NULL;
        if(matrix[index] == NULL)
            matrix[index] = temp;
        else
        {
            last = matrix[index];
            while (last->next !=NULL) last = last->next;
            last->next = temp;
        }
    }
}
void SparseLL::Display()
{
    Element* temp = NULL;

    cout << "Display Matrix" << endl;
    for (int i = 0; i < m; i++)
    {
        temp = matrix[i];
        for (int j = 0; j < n; j++)
        {
            if(temp!= NULL && temp->col == j)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }    
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
SparseLL SparseLL::add(SparseLL *s)
{
    if(m != s->m || n !=s->n)
        return SparseLL(0,0,0);
    SparseLL *sum = new SparseLL(m, n, num+s->num);

    Element *p,*q,*tail, *temp;
    for(int i=0; i<m; i++)
    {
        p = matrix[i]; q = s->matrix[i]; tail = temp = NULL;
        // r = new Element;
        while (p&&q)
        {
            if(p->col < q->col)
            {
                temp = new Element;
                temp->col = p->col;
                temp->data = p->data;
                temp->next = NULL;
                p = p->next;

            }
            else if(p->col > q->col)
            {
                temp = new Element;
                temp->col = q->col;
                temp->data = q->data;
                temp->next = NULL;
                q = q->next;

            }
            else /* p->col == q->col */
            {
                temp = new Element;
                temp->col = p->col;
                temp->data = p->data + q->data;
                temp->next = NULL;

                p = p->next;
                q = q->next;
            }
            if(sum->matrix[i] == NULL)
                sum->matrix[i] = tail = temp;
            else
            {
                tail->next = temp;
                tail= tail->next;
            }
        }
        if (p) tail->next = p;
        if (q) tail->next = q;       
    }
    return *sum;
}



int main()
{
    SparseLL A;
    A.Create();
    A.Display();


    SparseLL B;
    B.Create();
    B.Display();

    SparseLL S = A.add(&B);

    S.Display();
    return 0;
}
