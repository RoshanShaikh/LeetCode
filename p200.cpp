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

    void bfs(int row, int col, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;

        q.push({row, col});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // visited[r][c] = true;
            grid[r][c] = '0';

            vector<pair<int, int>> adj = adjacent(r, c);

            for (int i = 0; i < adj.size(); i++)
            {
                int rAdj = adj[i].first;
                int cAdj = adj[i].second;

                if (grid[rAdj][cAdj] == '1')
                {
                    grid[rAdj][cAdj] = '0';
                    q.push({rAdj, cAdj});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, grid);
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution ob;
    vector<vector<char>> c = {{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}};

    cout << ob.numIslands(c);
    return 0;
}