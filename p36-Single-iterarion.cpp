#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        /*
        unordered_set<string> set;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                    if (!set.insert(to_string(board[i][j]) + "-row-" + to_string(i)).second)
                        return false;
        return true;
        */
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                bool row = rows[i].insert(board[i][j]).second;
                bool col = cols[j].insert(board[i][j]).second;
                bool square = squares[(i / 3) * 3 + (j / 3)].insert(board[i][j]).second;
                if (!(row && col && square))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> v = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24, 25, 26, 27},
        {28, 29, 30, 31, 32, 33, 34, 35, 36},
        {37, 38, 39, 40, 41, 42, 43, 44, 45},
        {46, 47, 48, 49, 50, 51, 52, 53, 54},
        {55, 56, 57, 58, 59, 60, 61, 62, 63},
        {64, 65, 66, 67, 68, 69, 70, 71, 72},
        {73, 74, 75, 76, 77, 78, 79, 80, 81},
    };
    Solution().isValidSudoku(v);
    return 0;
}