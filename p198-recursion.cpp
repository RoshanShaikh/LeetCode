#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int index, vector<int> &nums)
    {
        if (index == 0)
            return nums[index];
        if (index < 0)
            return 0;

        int pick = nums[index] + solve(index - 2, nums);
        int not_pick = solve(index - 1, nums);

        return max(pick, not_pick);
    }

public:
    int rob(vector<int> &nums)
    {
        return solve(nums.size() - 1, nums);
    }
};

int main()
{
    vector<int> v = {2, 1, 4, 9};
    cout << Solution().rob(v);
    return 0;
}