// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool canColor(bool graph[3][3], int n, int node, int col, vector<int> &colors)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && colors[i] == col)
            return false;
    }
    return true;
}

bool solve(bool graph[3][3], int m, int n, int node, vector<int> &colors)
{
    if (node == n)
        return true;
    for (int i = 0; i < m; i++)
    {
        if (canColor(graph, n, node, i, colors))
        {
            colors[node] = i;
            if (solve(graph, m, n, node + 1, colors))
                return true;
            colors[node] = -1;
        }
    }
    return false;
}
bool graphColoring(bool graph[3][3], int m, int n)
{
    // your code here
    vector<int> colors(n, -1);
    return solve(graph, m, n, 0, colors);
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[3][3];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends