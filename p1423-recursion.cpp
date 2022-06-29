#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &cardPoints, int &k, int index, int start, int end, int &sum, int &ans)
    {
        if (start > end || index == k)
        {
            ans = max(ans, sum);
            return;
        }

        // take start
        sum += cardPoints[start];
        ans = max(ans, sum);
        solve(cardPoints, k, index + 1, start + 1, end, sum, ans);
        sum -= cardPoints[start];

        // take end
        sum += cardPoints[end];
        ans = max(ans, sum);
        solve(cardPoints, k, index + 1, start, end - 1, sum, ans);
        sum -= cardPoints[end];
    }

public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int ans = INT_MIN;
        int sum = 0;
        solve(cardPoints, k, 0, 0, cardPoints.size() - 1, sum, ans);
        return ans;
    }
};

int main()
{

    return 0;
}