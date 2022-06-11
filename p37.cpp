#include <bits/stdc++.h>
using namespace std;

class Solution
{
    pair<int, int> findEmptyCell(vector<vector<char>> &board, int row, int col)
    {
        for (int i = row; i < 9; i++)
        {
            int j = (i == row) ? col : 0;
            for (j; j < 9; j++)
            {
                if (board[i][j] == '.')
                    return {i, j};
            }
        }
        return {-1, -1};
    }
    bool possible(int row, int col, char tofill, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == tofill ||
                board[i][col] == tofill ||
                board[i / 3 + (row / 3) * 3][i % 3 + (col / 3) * 3] == tofill)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int row, int col)
    {
        pair<int, int> emptyCell = findEmptyCell(board, row, col);
        int i = emptyCell.first;
        int j = emptyCell.second;
        if (i == -1)
            return true;
        for (int k = '1'; k <= '9'; k++)
        {
            if (!possible(i, j, k, board))
                continue;
            board[i][j] = k;
            if (solve(board, i, j))
            {
                return true;
            }
            board[i][j] = '.';
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        pair<int, int> emptyCell = findEmptyCell(board, 0, 0);
        int i = emptyCell.first;
        int j = emptyCell.second;
        if (i == -1)
            return;
        solve(board, i, j);
    }
};

int main()
{

    return 0;
}