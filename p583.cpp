#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int lcs(string w1, string w2)
    {
        int n = w1.size();
        int m = w2.size();
        int dp[n + 1][m + 1] = {0};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (w1[i - 1] == w2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int LCS = lcs(word1, word2);
        return word1.size() - 2 * LCS + word2.size();
    }
};

int main()
{

    return 0;
}