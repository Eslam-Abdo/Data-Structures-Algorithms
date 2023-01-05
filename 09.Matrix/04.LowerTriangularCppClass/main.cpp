#include <iostream>
using namespace std;

class LowerTri
{
private:
    int *A;
    int n;
public:
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTri(){ delete [] A;}
    
    int GetDimention() {return n;}
    void Display(bool row=true);

    void SetRowMajor(int i, int j, int x);
    void SetColMajor(int i, int j, int x);
    int  GetRowMajor(int i, int j);
    int  GetColMajor(int i, int j);

};

void LowerTri::SetRowMajor(int i, int j, int x)
{
    if(i >= j)
        A[i*(i-1)/2 + j-1] = x;
}
void LowerTri::SetColMajor(int i, int j, int x)
{
    if(i >= j)
        A[n*(j-1) - (((j-1)*(j-2))/2) + (i-j)] = x;
}
int LowerTri::GetRowMajor(int i, int j)
{
    if(i >= j)
        return A[i*(i-1)/2 + j-1];
    else
        return 0;
}
int LowerTri::GetColMajor(int i, int j)
{
    if(i >= j)
        return A[n*(j-1) - (((j-1)*(j-2))/2) + (i-j)];
    else
        return 0;
}
void LowerTri::Display(bool row)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i >= j)
            {
                if(row)
                    cout << GetRowMajor(i,j) << " ";
                else
                    cout << GetColMajor(i,j) << " ";
            }
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    // int d;
    // cout << "Enter Dimensions ";
    // cin >> d;

    // LowerTri lm(d);

    // int x;
    // cout<< "Enter All Elements" << endl;
    // for (int i = 1; i <= d; i++)
    // {
    //     for (int j = 1; j <= d; j++)
    //     {
    //         cin >> x;
    //         lm.Set(i,j,x);
    //     }
    // }
    // cout << "++++++++++++Display+++++++++++++++" << endl;
    // lm.Display();


    LowerTri rm(4);
    rm.SetRowMajor(1, 1, 1);
    rm.SetRowMajor(2, 1, 2);
    rm.SetRowMajor(2, 2, 3);
    rm.SetRowMajor(3, 1, 4);
    rm.SetRowMajor(3, 2, 5);
    rm.SetRowMajor(3, 3, 6);
    rm.SetRowMajor(4, 1, 7);
    rm.SetRowMajor(4, 2, 8);
    rm.SetRowMajor(4, 3, 9);
    rm.SetRowMajor(4, 4, 10);
    cout << "++++++++++++Display Row Major+++++++++++++++" << endl;
    rm.Display();
    cout << endl;

    LowerTri cm(4);
    cm.SetColMajor(1, 1, 1);
    cm.SetColMajor(2, 1, 2);
    cm.SetColMajor(2, 2, 3);
    cm.SetColMajor(3, 1, 4);
    cm.SetColMajor(3, 2, 5);
    cm.SetColMajor(3, 3, 6);
    cm.SetColMajor(4, 1, 7);
    cm.SetColMajor(4, 2, 8);
    cm.SetColMajor(4, 3, 9);
    cm.SetColMajor(4, 4, 10);
    cout << "++++++++++++Display Col Major+++++++++++++++" << endl;

    cm.Display(false);
    cout << endl;


    return 0;
}
