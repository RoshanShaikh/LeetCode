#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int index, vector<int> output)
    {
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        solve(nums, index + 1, output);
        output.push_back(nums[index]);
        solve(nums, index + 1, output);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int index = 0;
        vector<int> output;
        solve(nums,  index, output);
        return ans;
    }
};

int main()
{
    return 0;
}