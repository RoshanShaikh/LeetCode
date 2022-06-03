#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + text1[i - 1];
                }
                else
                {
                    if (dp[i][j - 1].size() > dp[i - 1][j].size())
                        dp[i][j] = dp[i][j - 1];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        printf("%s\n", dp[n][m].c_str());
        return dp[n][m].size();
    }
};

int main()
{
    return 0;
}