#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans(m * n);

        char dir = 'r';
        int left = 0, top = 0;
        int bottom = n - 1;
        int right = m - 1;
        int count = 0;

        while (left <= right && top <= bottom)
        {
            switch (dir)
            {
            case 'r':
                for (int i = left; i <= right; i++)
                {
                    ans[count++] = matrix[top][i];
                }
                top++;
                dir = 'd';
                break;
            case 'd':
                for (int i = top; i <= bottom; i++)
                {
                    ans[count++] = matrix[i][right];
                }
                right--;
                dir = 'l';
                break;
            case 'l':
                for (int i = right; i >= left; i--)
                {
                    ans[count++] = matrix[bottom][i];
                }
                bottom--;
                dir = 'u';
                break;
            case 'u':
                for (int i = bottom; i >= top; i--)
                {
                    ans[count++] = matrix[i][left];
                }
                left++;
                dir = 'r';
                break;

            default:
                break;
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12}};

    vector<int> ans = Solution().spiralOrder(v);

    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}