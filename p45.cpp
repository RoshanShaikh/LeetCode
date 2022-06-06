#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int max_reachable = nums[0];
        int n = nums.size();
        if (n == 1)
            return 0;
        int max_index = 0;
        int count = 0;
        while (max_reachable < n - 1)
        {
            int j = max_index;
            int max_reach = max_reachable;
            for (int i = j; i <= max_reach; i++)
            {
                if (nums[i] + i > max_reachable)
                {
                    max_index = i;
                    max_reachable = i + nums[i];
                }
            }
            count++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 0, 6};
    Solution().jump(nums);
    return 0;
}