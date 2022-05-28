#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        /*
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < n)
            {
                swap(nums[i], nums[nums[i]]);
                if (i != nums[i])
                    i--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
        */
        /*
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
        }
        return total - sum;
        */

        for (int i = 0; i < n; i++)
        {
            while (nums[i] != n && nums[i] != i)
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};

int main()
{
    vector<int> v = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution().missingNumber(v);
    return 0;
}