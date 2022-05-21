#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int target = nums[k] * -1;
            int i = k + 1, j = n - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    while (nums[i] == nums[i - 1] && i < j)
                        i++;
                }
                else if (nums[i] + nums[j] > target)
                    j--;
                else
                    i++;
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> ans = {{1, 2, 3}, {3, 7, 9}, {2, 5, 4}};
    vector<int> v = {1, 2, 3};
    cout << (find(ans.begin(), ans.end(),
                  [&v](vector<int> &k)
                  {
                      vector<int>::iterator vi = v.begin(), ki = k.begin();
                      while (vi < v.end() && ki < k.end())
                      {
                          if (*vi != *ki)
                          {
                              return false;
                          }
                          vi++;
                          ki++;
                      }
                      return true;
                  }) != ans.end()
                 ? "Found"
                 : "Not");
    return 0;
}