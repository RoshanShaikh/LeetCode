#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // map<int, int> map;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > 0)
        //         map[nums[i]] = 1;
        // }
        // int j = 1;
        // for (auto &&i : map)
        // {
        //     if (i.second == 1 && i.first == j)
        //         j++;
        //     else
        //         break;
        // }
        // return j;

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                count++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i+1 && nums[i] > 0 && nums[i] <= count && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return count + 1;
    }
};

int main()
{
    vector<int> v = {1,1};
    Solution().firstMissingPositive(v);
    return 0;
}