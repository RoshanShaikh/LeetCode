#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j > i && nums[j] <= nums[i])
                j--;
            swap(nums[j], nums[i]);
        }
        reverse(nums, i + 1);
        for (auto &&i : nums)
        {
            cout << i << " ";
        }
    }

    void reverse(vector<int> &nums, int start)
    {
        int end = nums.size() - 1;
        while (end > start && start < nums.size() - 1)
        {
            swap(nums[start++], nums[end--]);
        }
    }
};

int main()
{
    vector<int> v = {1, 3, 2};
    Solution().nextPermutation(v);
    return 0;
}