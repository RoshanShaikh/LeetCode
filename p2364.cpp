#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long nC2(int n)
    {
        return ((long long)n * n - 1) / 2;
    }

public:
    long long countBadPairs(vector<int> &nums)
    {
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] - i;
            mp[nums[i]]++;
        }

        ans = nC2(nums.size());
        for (auto &&pr : mp)
        {
            if (pr.second > 1)
            {
                ans -= nC2(pr.second);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}