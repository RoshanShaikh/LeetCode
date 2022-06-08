#include <bits/stdc++.h>
using namespace std;

/*
class Solution
{
private:
    set<vector<int>> set;
    void solve(vector<int> &nums, int index, int &n)
    {
        if (index == n)
        {
            set.insert(nums);
            return;
        }
        for (int i = index; i < n; i++)
        {
            swap(nums[i], nums[index]);
            solve(nums, index + 1, n);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        solve(nums, 0, n);
        return vector<vector<int>>(set.begin(), set.end());
    }
};
*/
class Solution
{
private:
    bool canPermute(int index, int curr, vector<int> nums)
    {
        for (int i = index; i < curr; i++)
        {
            if (nums[i] == nums[curr])
                return false;
        }
        return true;
    }
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index, int &n)
    {
        if (index == n - 1)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (i != index && !canPermute(index, i, nums))
                continue;
            swap(nums[i], nums[index]);
            solve(nums, ans, index + 1, n);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(nums, ans, 0, n);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> ans = Solution().permuteUnique(v);
    for (auto &&l : ans)
    {
        for (auto &&i : l)
        {
            cout << i;
        }
        cout << " ";
    }

    return 0;
}