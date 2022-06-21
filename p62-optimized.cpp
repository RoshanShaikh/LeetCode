#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long uniquePaths(int m, int n)
    {
        vector<long long> dp(m, 1);
        m--;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    cout << Solution().uniquePaths(n, m);
    return 0;
}