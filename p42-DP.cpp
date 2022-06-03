#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> prev(n), next(n);
        int prevmax = INT_MIN, nextmax = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            prevmax = max(prevmax, height[i]);
            prev[i] = prevmax;
            nextmax = max(nextmax, height[n - i - 1]);
            next[n - i - 1] = nextmax;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(next[i], prev[i]) - height[i];
        }
        return ans;
    }
};

int main()
{

    return 0;
}