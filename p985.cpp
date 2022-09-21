#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> ans(n);
        int sum = 0;

        for (auto &&i : nums)
        {
            if (i % 2 == 0)
                sum += i;
        }

        for (int i = 0; i < n; i++)
        {
            int val = queries[i][0];
            int idx = queries[i][1];

            if (nums[idx] % 2 == 0)
                sum -= nums[idx];

            nums[idx] += val;

            if (nums[idx] % 2 == 0)
                sum += nums[idx];

            ans[i] = sum;
        }

        return ans;
    }
};

int main()
{

    return 0;
}