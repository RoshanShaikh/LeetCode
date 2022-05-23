#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int l = 0; l < n; l++)
        {
            if (l > 0 && nums[l] == nums[l - 1])
                continue;
            for (int k = l + 1; k < n;)
            {

                int tmptarget = target - nums[k] - nums[l];
                int i = k + 1, j = n - 1;
                while (i < j)
                {
                    if (nums[i] + nums[j] == tmptarget)
                    {
                        ans.push_back({nums[l], nums[k], nums[i], nums[j]});
                        i++;
                        while (nums[i] == nums[i - 1] && i < j)
                            i++;
                    }
                    else if (nums[i] + nums[j] > tmptarget)
                        j--;
                    else
                        i++;
                }
                k++;
                while (k < n && nums[k] == nums[k - 1])
                {
                    k++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {2, 2, 2, 2, 2};
    vector<vector<int>> vt = Solution().fourSum(v, 8);
    for (auto &&i : vt)
    {
        cout << "[";
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << "]\n";
    }

    return 0;
}