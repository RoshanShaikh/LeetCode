#include <bits/stdc++.h>
using namespace std;

class Solution
{
    inline bool canMoveRight(vector<vector<int>> &board, int &row, int &col)
    {
        return (col + 1 < board.size() && board[row][col + 1] == 1);
    }

    inline bool canMoveLeft(vector<vector<int>> &board, int &row, int &col)
    {
        return (col - 1 >= 0 && board[row][col - 1] == 1);
    }

    inline bool canMoveDown(vector<vector<int>> &board, int &row, int &col)
    {
        return (row + 1 < board.size() && board[row + 1][col] == 1);
    }

    inline bool canMoveUp(vector<vector<int>> &board, int &row, int &col)
    {
        return (row - 1 >= 0 && board[row - 1][col] == 1);
    }

    void solve(vector<vector<int>> &board, int &n, int row, int col, string &path, vector<string> &ans)
    {
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }
        if (canMoveDown(board, row, col))
        {
            board[row][col] = 0;
            path.push_back('D');
            solve(board, n, row + 1, col, path, ans);
            board[row][col] = 1;
            path.pop_back();
        }
        if (canMoveLeft(board, row, col))
        {
            board[row][col] = 0;
            path.push_back('L');
            solve(board, n, row, col - 1, path, ans);
            board[row][col] = 1;
            path.pop_back();
        }
        if (canMoveRight(board, row, col))
        {
            board[row][col] = 0;
            path.push_back('R');
            solve(board, n, row, col + 1, path, ans);
            board[row][col] = 1;
            path.pop_back();
        }
        if (canMoveUp(board, row, col))
        {
            board[row][col] = 0;
            path.push_back('U');
            solve(board, n, row - 1, col, path, ans);
            board[row][col] = 1;
            path.pop_back();
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string path = "";
        if (m[0][0] != 0)
            solve(m, n, 0, 0, path, ans);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}