#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int n, int col, vector<vector<string>> &ans, vector<string> &placed, vector<int> row, vector<int> upperDia, vector<int> lowerDia)
    {
        if (col == n)
        {
            ans.push_back(placed);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (row[i] != 1 && upperDia[n - 1 + col - i] != 1 && lowerDia[col + i] != 1)
            {
                row[i] = 1;
                upperDia[n - 1 + col - i] = 1;
                lowerDia[col + i] = 1;
                placed[i][col] = 'Q';
                solve(n, col + 1, ans, placed, row, upperDia, lowerDia);
                placed[i][col] = '.';
                row[i] = 0;
                upperDia[n - 1 + col - i] = 0;
                lowerDia[col + i] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string dots = string(n, '.');
        vector<string> placed(n, dots);
        vector<int> row(n, 0), upperDia(2 * n - 1, 0), lowerDia(2 * n - 1, 0);
        solve(n, 0, ans, placed, row, upperDia, lowerDia);
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