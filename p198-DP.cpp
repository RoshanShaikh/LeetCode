#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int rob(vector<int> &nums)
    {
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notpick = prev1;

            int current = max(pick, notpick);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main()
{
    vector<int> v = {2, 1, 4, 9};
    cout << Solution().rob(v);
    return 0;
}