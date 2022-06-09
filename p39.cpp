#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void combinationSum(vector<int> &nums, vector<int> &seq, int k, int index, int sum, vector<vector<int>> &ans)
    {
        if (sum == k)
        {
            ans.push_back(seq);
            return;
        }
        if (index >= nums.size())
            return;
        if (sum > k)
        {
            return;
        }
        seq.push_back(nums[index]);
        combinationSum(nums, seq, k, index, sum + nums[index], ans);
        seq.pop_back();
        combinationSum(nums, seq, k, index + 1, sum, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int k)
    {
        vector<vector<int>> ans;
        vector<int> seq;
        combinationSum(nums, seq, k, 0, 0, ans);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    int k;
    cin >> k;
    vector<vector<int>> ans = Solution().combinationSum(in, k);
    for (auto &&list : ans)
    {
        for (auto &&ele : list)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}