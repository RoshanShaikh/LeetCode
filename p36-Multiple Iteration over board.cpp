#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < 9; i++)
        {
            map.clear();
            for (int j = 0; j < 9; j++)
            {
                map[board[i][j]]++;
                if (map[board[i][j]] > 1 && board[i][j] != '.')
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            map.clear();
            for (int j = 0; j < 9; j++)
            {
                map[board[j][i]]++;
                if (map[board[j][i]] > 1 && board[j][i] != '.')
                    return false;
            }
        }
        int n = 0;
        while (n < 9)
        {
            map.clear();
            int k = 0;
            while (k < 9)
            {
                map.clear();
                for (int i = n; i < n + 3; i++)
                {
                    for (int j = k; j < k + 3; j++)
                    {
                        map[board[i][j]]++;
                        if (map[board[i][j]] > 1 && board[i][j] != '.')
                            return false;
                    }
                }
                k += 3;
            }
            n += 3;
        }
        return true;
    }
};

int main()
{
    int n = 0;
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