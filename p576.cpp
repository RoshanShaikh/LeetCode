#include <bits/stdc++.h>
using namespace std;

class Solution
{
    pair<int, int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    long solve(int &m, int &n, int &maxMoves, int row, int col, vector<vector<vector<int>>> &memo)
    {
        if (row >= m || col >= n || row < 0 || col < 0)
        {
            return 1;
        }
        if (maxMoves <= 0)
            return 0;

        if (memo[row][col][maxMoves] != -1)
            return memo[row][col][maxMoves];

        long res = 0;
        maxMoves--;
        for (int i = 0; i < 4; i++)
        {
            res += solve(m, n, maxMoves, row + dir[i].first, col + dir[i].second, memo);
        }
        maxMoves++;

        memo[row][col][maxMoves] = res;
        return res % 1000000007;
    }

public:
    int
    findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> memo(51, vector<vector<int>>(51, vector<int>(51, -1)));
        int movesTaken = 0;
        return solve(m, n, maxMove, startRow, startColumn, memo);
    }
};

int main()
{
    cout << Solution().findPaths(2, 2, 2, 0, 0);
    return 0;
}