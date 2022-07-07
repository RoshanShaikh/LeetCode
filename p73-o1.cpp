#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();
        int m = matrix.size();

        int rowZero = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if (i > 0)
                        matrix[i][0] = 0;
                    else
                        rowZero = 0;
                }
            }
        }

        for (int i = m - 1; i > 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0)
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }

        if (rowZero == 0)
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    for (auto &&row : v)
    {
        for (auto &&i : row)
        {
            cout << setw(3) << i << " ";
        }
        cout << "\n";
    }
    Solution().setZeroes(v);

    cout << endl
         << endl;
    for (auto &&row : v)
    {
        for (auto &&i : row)
        {
            cout << setw(3) << i << " ";
        }
        cout << "\n";
    }

    return 0;
}