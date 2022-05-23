#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int diff = INT_MAX;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int start = i + 1, end = nums.size() - 1;
            while (start < end)
            {
                if (abs(target - (nums[i] + nums[start] + nums[end])) < diff)
                {
                    diff = abs(target - (nums[i] + nums[start] + nums[end]));
                    res = nums[i] + nums[start] + nums[end];
                }
                if (diff == 0)
                    return res;
                if (nums[i] + nums[start] + nums[end] < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {0, 0, 0};
    cout << Solution().threeSumClosest(v, 1);
    return 0;
}