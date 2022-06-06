#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /* Using Extra Space
        int n = nums.size();
        vector<int> ans(n);
        int index = 0;
        int i = n - k;
        while (index < n)
        {
            ans[index++] = nums[i++];
            i %= n;
        }
        nums.clear();
        nums = ans;
        */

        /* Without Using Extra Space
         */
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (k % nums.size()));
        reverse(nums.begin() + (k % nums.size()), nums.end());
    }
};

int main()
{

    return 0;
}