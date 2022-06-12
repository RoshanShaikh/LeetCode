#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int noOfOrgs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    noOfOrgs++;
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                for (auto &&d : dir)
                {
                    int r = i + d.first;
                    int c = j + d.second;
                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        noOfOrgs--;
                        q.push({r, c});
                    }
                }
                q.pop();
            }
            ans++;
        }
        if (noOfOrgs == 0)
            if (ans > 0)
                return ans - 1;
            else
                return ans;
        return -1;
    }
};

int main()
{

    return 0;
}