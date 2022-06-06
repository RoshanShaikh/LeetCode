#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        /* Using sort
        for (int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        return nums;
        */
        /* Without Using Sort*/
        int n = nums.size();
        int l = 0;
        vector<int> ans(n);
        n--;
        for (int i = n; i >= 0; i--)
        {
            if (abs(nums[l]) > abs(nums[i]))
                ans[i] = nums[l] * nums[l++];
            else
                ans[i] = nums[n] * nums[n--];
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution().sortedSquares(nums);
    return 0;
}