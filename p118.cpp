#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        ans.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    for (int i = 0; i < 30; i++)
    {
        cout << i + 1 << endl;
    }

    return 0;
}