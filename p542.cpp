#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;

            for (auto &&d : dir)
            {
                int r = i + d.first;
                int c = j + d.second;
                if (r >= 0 && r < n && c >= 0 && c < m)
                {
                    if (ans[i][j] + 1 < ans[r][c])
                    {
                        ans[r][c] = ans[i][j] + 1;
                        q.push({r, c});
                    }
                }
            }
            q.pop();
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{0, 0, 0},
                             {0, 1, 0},
                             {1, 1, 1}};
    Solution().updateMatrix(v);
    return 0;
}