#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool canPlace(int row, int col, vector<int> placed)
    {
        for (int i = 0; i < placed.size(); i++)
        {
            if (row == placed[i])
                return false;
            if (abs(row - placed[i]) == abs(col - i))
                return false;
        }
        return true;
    }
    void solve(int n, int col, vector<vector<int>> &ans, vector<int> &placed)
    {
        if (col == n)
        {
            ans.push_back(placed);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!canPlace(i, col, placed))
                continue;
            placed.push_back(i);
            solve(n, col + 1, ans, placed);
            placed.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<int>> positions;
        vector<int> placed;
        solve(n, 0, positions, placed);
        string dots = "";
        for (int i = 0; i < n; i++)
            dots += '.';
        for (int i = 0; i < positions.size(); i++)
        {
            vector<string> tmp(n, dots);
            for (int j = 0; j < n; j++)
            {
                tmp[j][positions[i][j]] = 'Q';
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans = Solution().solveNQueens(n);
    for (auto &&placed : ans)
    {
        for (auto &&i : placed)
        {
            cout << i << "\n";
        }
        cout << "---------" << endl;
    }

    return 0;
}