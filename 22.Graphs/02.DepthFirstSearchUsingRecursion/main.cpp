#include <iostream>

using namespace std;

void DFS(int A[][8], int start, int n)
{
    static int visited[8] = {0};
    if(visited[start] == 0)
    {
        cout << start << ", ";
        visited[start] = 1;
        for(int v = 1; v <= n; v++)
            if(A[start][v] == 1 && visited[v] == 0)
                DFS(A,v,n);
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