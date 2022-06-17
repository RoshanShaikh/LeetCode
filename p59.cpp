#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));

        int left = 0, top = 0;
        int bottom = n - 1, right = n - 1;

        int count = 1;
        char dir = 'r';

        while (left <= right && top <= bottom)
        {
            switch (dir)
            {
            case 'r':
                for (int i = left; i <= right; i++)
                {
                    ans[top][i] = count++;
                }
                dir = 'd';
                top++;
                break;
            case 'd':
                for (int i = top; i <= bottom; i++)
                {
                    ans[i][right] = count++;
                }
                dir = 'l';
                right--;
                break;
            case 'l':
                for (int i = right; i >= left; i--)
                {
                    ans[bottom][i] = count++;
                }
                dir = 'u';
                bottom--;
                break;
            case 'u':
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][left] = count++;
                }
                dir = 'r';
                left++;
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
    vector<vector<int>> ans = Solution().generateMatrix(4);

    for (auto &&v : ans)
    {
        for (auto &&i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}