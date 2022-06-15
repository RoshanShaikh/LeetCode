#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index == 0)
            return nums[index];

        if (index < 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int pick, not_pick;

        pick = nums[index] + solve(index - 2, nums, dp);
        not_pick = solve(index - 1, nums, dp);

        return max(pick, not_pick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums.size() - 1, nums, dp);
    }
};

int main()
{
    vector<int> v = {2, 1, 4, 9};
    cout << Solution().rob(v);
    return 0;
}