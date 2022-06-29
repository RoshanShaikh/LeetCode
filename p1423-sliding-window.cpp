#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        for (int i = 1; i < n; i++)
        {
            cardPoints[i] += cardPoints[i - 1];
        }

        int ans = INT_MIN;

        for (int i = 0; i < k; i++)
        {
            int sum = cardPoints[k - i - 1] + cardPoints[n - 1] - cardPoints[n - i - 1];
            ans = max(ans, sum);
        }
        
        if (k != n)
        {
            int sum = cardPoints[n - 1] - cardPoints[n - k - 1];
            ans = max(ans, sum);
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 1};

    cout << Solution().maxScore(v, 3);
    return 0;
}