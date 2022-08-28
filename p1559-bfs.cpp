#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int m, n;

    vector<pair<int, int>> adjacent(int row, int col)
    {
        vector<pair<int, int>> ans;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < 4; i++)
        {
            int r = dir[i].first;
            int c = dir[i].second;

            if (row + r < m && row + r >= 0 && col + c >= 0 && col + c < n)
            {
                ans.push_back({row + r, col + c});
            }
        }

        return ans;
    }

    bool bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        queue<vector<int>> q;
        q.push({row, col, -1, -1});
        char c = grid[row][col];
        while (!q.empty())
        {
            int currI = q.front()[0];
            int currJ = q.front()[1];
            int parentI = q.front()[2];
            int parentJ = q.front()[3];

            q.pop();

            if (visited[currI][currJ])
                return true;

            visited[currI][currJ] = true;

            vector<pair<int, int>> adj = adjacent(currI, currJ);

            for (int i = 0; i < adj.size(); i++)
            {
                int childI = adj[i].first;
                int childJ = adj[i].second;

                if (grid[childI][childJ] == c && (childI != parentI || childJ != parentJ))
                    q.push({childI, childJ, currI, currJ});
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && bfs(i, j, grid, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> grid =
        // {{'a', 'b', 'b'},
        //  {'b', 'z', 'b'},
        //  {'b', 'b', 'a'}};
        {{'b', 'a'},
         {'a', 'a'}};
    // {{'a', 'a', 'a', 'a'},
    //  {'a', 'b', 'b', 'a'},
    //  {'a', 'b', 'b', 'a'},
    //  {'a', 'a', 'a', 'a'}};

    Solution ob;
    cout << ob.containsCycle(grid);
    return 0;
}