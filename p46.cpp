#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index, int &n)
    {
        if (index == n - 1)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {
            swap(nums[i], nums[index]);
            solve(nums, ans, index + 1, n);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(nums, ans, 0, n);
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> a = Solution().permute(v);
    for (auto &&i : a)
    {
        for (auto &&j : i)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}