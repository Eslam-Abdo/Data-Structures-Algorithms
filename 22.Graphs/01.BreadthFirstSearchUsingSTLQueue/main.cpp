#include <iostream>
#include <queue>

using namespace std;

void BFS(int A[][8], int start, int n)
{
    queue<int> q;
    int visited[8] = {0};
    // Initial
    // Visit vertex
    cout << start << ", "; 
    visited[start] = 1;
    q.emplace(start);

    // Explore
    while (!q.empty())
    {
        // Vertex u for exploring
        int u = q.front();
        q.pop();
        // Adjacent vertices of vertex u
        for (int v = 1; v <= n; v++)
        {
            // Adjacent vertex and not visited
            if(A[u][v] == 1 && visited[v] == 0)
            {
                // Visit vertex
                cout << v << ", ";
                visited[v] = 1;
                q.emplace(v);
            }
        }
    }
    cout << endl;
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
 
    cout << "Vertex: 1 -> " << flush;
    BFS(A, 1, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(A, 4, 8);
 
 
    return 0;
}