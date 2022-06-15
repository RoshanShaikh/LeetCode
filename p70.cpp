#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[46] = {0};

public:
    Solution()
    {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= 45; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    int climbStairs(int n)
    {
        return dp[n];
    }
};

int main()
{
    for (int i = 0; i < 45; i++)
    {
        cout << i + 1 << endl;
    }

    return 0;
}