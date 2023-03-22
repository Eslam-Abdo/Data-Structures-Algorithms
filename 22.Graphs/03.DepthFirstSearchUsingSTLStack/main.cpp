#include <iostream>
#include <stack>

using namespace std;

void DFS(int A[][8], int start, int n)
{
    stack<int> stk;
    int visited[8] = {0};
    stk.emplace(start);

    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
       
        if(visited[u] == 0)
        {
            cout << u << ", ";
            visited[u] = 1;
            for(int v = n-1; v >= 0; v--)
                if(A[u][v] == 1 && visited[v] == 0)
                    stk.emplace(v);
        }
    }
    
}

int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
 
    cout << "Vertex: 4 -> " << flush;
    DFS(A, 4, 8);
    cout << endl;
 
 
    return 0;
}