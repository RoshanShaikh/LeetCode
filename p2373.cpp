#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxMatrix(vector<vector<int>> &grid, int row, int col)
    {
        int maxi = INT_MIN;
        for (int i = row; i < 3 + row; i++)
        {
            for (int j = col; j < 3 + col; j++)
            {
                maxi = max(maxi, grid[i][j]);
            }
        }

        return maxi;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                ans[i][j] = maxMatrix(grid, i, j);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}