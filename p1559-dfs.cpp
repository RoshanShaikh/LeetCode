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

    bool dfs(int row, int col, int pr, int pc, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if (visited[row][col])
            return true;

        visited[row][col] = true;

        vector<pair<int, int>> adj = adjacent(row, col);

        for (int i = 0; i < adj.size(); i++)
        {
            int childI = adj[i].first;
            int childJ = adj[i].second;

            if (grid[childI][childJ] == grid[row][col] && (childI != pr || childJ != pc))
                if (dfs(childI, childJ, row, col, grid, visited))
                    return true;
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
                if (!visited[i][j] && dfs(i, j, -1, -1, grid, visited))
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
        {{'a', 'a'},
         {'a', 'a'}};
    // {{'a', 'a', 'a', 'a'},
    //  {'a', 'b', 'b', 'a'},
    //  {'a', 'b', 'b', 'a'},
    //  {'a', 'a', 'a', 'a'}};

    Solution ob;
    cout << ob.containsCycle(grid);

    return 0;
}