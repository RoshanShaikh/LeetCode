#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return true;

        if (n == 0)
            return false;

        int maxReachable = nums[0];
        int maxIndex = 0;

        while (maxReachable < n - 1)
        {
            int j = maxIndex;
            int max = maxReachable;
            for (j; j <= max; j++)
            {
                if (j + nums[j] > maxReachable)
                {
                    maxReachable = j + nums[j];
                    maxIndex = j;
                }
            }
            if (max == maxReachable)
                return false;
        }

        if (maxReachable >= n - 1)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}