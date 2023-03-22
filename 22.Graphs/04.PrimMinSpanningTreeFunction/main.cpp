#include <iostream>

using namespace std;

#define I       INT32_MAX


void PrimsMST(int G[][8], int n)
{
    int u,v, min{I};
    int near[8];
    int T[2][n-2] {0};

    // Initial: Find min cost edge
    for (int i = 1; i < n; i++)
    {
        near[i] = I; // Initialize track array with INFINITY
        for(int j = i; j < n; j++)
        {
            if (G[i][j] < min)
            {
                min = G[i][j];
                u = i;
                v = j;
            }   
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    near[u] = near[v] = 0; 

    // Initialize track array to track min cost edges
    for (int i = 1; i < n; i++)
    {
        if(near[i] != 0)
        {
            if(G[i][u] < G[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    
    // Repeat
    for (int i = 1; i < n-2; i++)
    {
        int k;
        min = I;
        for (int j = 1; j < n; j++)
        {
            if(near[j] != 0 && G[j][near[j]] < min)
            {
                k = j;
                min = G[j][near[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = near[k];
        near[k] = 0;

        // Update track array to track min cost edges
        for (int j = 1; j < n; j++)
            if(near[j] != 0 && G[j][k] < G[j][near[j]])
                near[j] = k;
    }
    // print path
    for (int i = 0; i < n-2; i++)
        cout << "(" << T[0][i] << "," << T[1][i] << ")" << endl;
}


int main()
{
    int cost [][8] {
            {I, I , I , I , I , I , I , I },
            {I, I , 25, I , I , I , 5 , I },
            {I, 25, I , 12, I , I , I , 10},
            {I, I , 12, I , 8 , I , I , I },
            {I, I , I , 8 , I , 16, I , 14},
            {I, I , I , I , 16, I , 20, 18},
            {I, 5 , I , I , I , 20, I , I },
            {I, I , 10, I , 14, 18, I , I },
    };

    int n = sizeof(cost[0])/sizeof(cost[0][0]);

    PrimsMST(cost,n);

    return 0;
}