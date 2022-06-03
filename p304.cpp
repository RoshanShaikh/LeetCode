#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>> &mat)
    {
        if (mat.empty() || mat[0].empty())
            return;
        matrix.resize(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        for (int i = 1; i <= mat.size(); i++)
        {
            for (int j = 1; j <= mat[0].size(); j++)
            {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = matrix[row2 + 1][col2 + 1] - matrix[row2 + 1][col1] - matrix[row1][col2 + 1] + matrix[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    vector<vector<int>> v = {{{3, 0, 1, 4, 2},
                              {5, 6, 3, 2, 1},
                              {1, 2, 0, 1, 5},
                              {4, 1, 0, 1, 7},
                              {1, 0, 3, 0, 5}}};
    NumMatrix *obj = new NumMatrix(v);

    return 0;
}