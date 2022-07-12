#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];

        // int n = nums.size();
        // unordered_map<int, int> mp;

        // for (int i = 0; i < n; i++)
        // {
        //     mp[nums[i]]++;
        // }

        // int ans = INT_MIN;
        // int freq = INT_MIN;

        // for (auto &&m : mp)
        // {
        //     if (m.second > freq)
        //     {
        //         freq = m.second;
        //         ans = m.first;
        //     }
        // }

        // return ans;
    }
};

int main()
{
    for (int i = 1; i < 20; i++)
    {
        cout << i << endl;
    }
    return 0;
}