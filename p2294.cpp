#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minNum = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (abs(minNum - nums[i]) <= k)
            {
                continue;
            }
            else
            {
                count++;
                minNum = nums[i];
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}