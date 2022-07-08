#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool solve(vector<vector<char>> &board, string &word, int index, int x, int y)
    {
        if (index == word.size())
            return true;

        if (word[index] != board[x][y])
            return false;

        char tmp = board[x][y];

        board[x][y] = '-';

        if (x + 1 < board.size() && solve(board, word, index + 1, x + 1, y))
            return true;

        if (y + 1 < board[0].size() && solve(board, word, index + 1, x, y + 1))
            return true;

        if (x - 1 >= 0 && solve(board, word, index + 1, x - 1, y))
            return true;

        if (y - 1 >= 0 && solve(board, word, index + 1, x, y - 1))
            return true;

        board[x][y] = tmp;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (solve(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}