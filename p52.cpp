#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool canPlace(vector<int> placed, int row, int col)
    {
        for (int i = 0; i < placed.size(); i++)
        {
            if (placed[i] == row || abs(row - placed[i]) == abs(col - i))
                return false;
        }
        return true;
    }
    void solve(int &n, int index, int &count, vector<int> &placed)
    {
        if (index == n)
        {
            count++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (canPlace(placed, i, index))
            {
                placed.push_back(i);
                solve(n, index + 1, count, placed);
                placed.pop_back();
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<int> placed;
        solve(n, 0, count, placed);
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().totalNQueens(n);
    return 0;
}