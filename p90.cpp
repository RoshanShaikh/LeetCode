#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void subsetsWithDup(vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans, int index)
    {
        ans.push_back(subset);
        for (int i = index; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            subsetsWithDup(nums, subset, ans, i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, subset, ans, 0);
        return ans;
    }
};

int main()
{

    return 0;
}