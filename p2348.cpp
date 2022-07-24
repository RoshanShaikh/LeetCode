#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int noOfZero = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                noOfZero++;
            else if (noOfZero > 0)
            {
                ans += (long long)(noOfZero) * (noOfZero + 1) / (long long)2;
                noOfZero = 0;
            }
        }

        if (nums[nums.size() - 1] == 0)
            ans += (long long)(noOfZero) * (noOfZero + 1) / (long long)2;

        return ans;
    }
};

int main()
{
    vector<int> arr = {0, 0, 0, 2, 0, 0};
    cout << Solution().zeroFilledSubarray(arr);
    return 0;
}