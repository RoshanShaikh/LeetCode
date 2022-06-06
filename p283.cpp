#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                count++;
        }
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[index] = nums[i];
                index++;
            }
        }
        for (int i = n - count; i < n; i++)
            nums[i] = 0;
    }
};

int main()
{
    vector<int> v =
        {0, 2, 5, 0, 2, 68, 9, 5, 0, 1};
    Solution().moveZeroes(v);
    return 0;
}