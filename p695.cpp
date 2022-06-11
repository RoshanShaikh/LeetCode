#include <bits/stdc++.h>
using namespace std;

class Solution
{
    pair<int, int> findNext1(vector<vector<int>> &board, int row, int col)
    {
        for (int i = row; i < board.size(); i++)
        {
            int j = (i == row) ? col : 0;
            for (j; j < board[0].size(); j++)
            {
                if (board[i][j] == 1)
                    return {i, j};
            }
        }
        return {-1, -1};
    }

    void solve(vector<vector<int>> &grid, int row, int col, int &maxArea)
    {
        pair<int, int> cellWith1 = findNext1(grid, row, col);
        int i = cellWith1.first;
        int j = cellWith1.second;
        while (i != -1)
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            int area = 0;
            while (!q.empty())
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
                {
                    area++;
                    grid[i][j] = 0;
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                    q.push({i + 1, j});
                    q.push({i - 1, j});
                }
            }
            maxArea = max(area, maxArea);
            cellWith1 = findNext1(grid, i, j);
            i = cellWith1.first;
            j = cellWith1.second;
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0;
        solve(grid, 0, 0, maxArea);
        return maxArea;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int ans = Solution().maxAreaOfIsland(grid);
    return 0;
}