#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int index, int &count, int &n, vector<bool> &col, vector<bool> &diag, vector<bool> &antiDiag, vector<int> &placed)
    {
        if (index == n)
        {
            count++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (col[i] && diag[index + n - i - 1] && antiDiag[index + i])
            {
                col[i] = diag[index + n - i - 1] = antiDiag[index + i] = false;
                placed.push_back(i);
                solve(index + 1, count, n, col, diag, antiDiag, placed);

                col[i] = diag[index + n - i - 1] = antiDiag[index + i] = true;
                placed.pop_back();
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<bool> col(n, true);
        vector<bool> diag(2 * n - 1, true);
        vector<bool> antiDiag(2 * n - 1, true);
        vector<int> placed;
        int count = 0;
        solve(0, count, n, col, diag, antiDiag, placed);
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