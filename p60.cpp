#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int k, int &fact, vector<int> &nums, string &ans)
    {
        if (nums.size() == 1)
        {
            ans.push_back('0' + nums[0]);
            return;
        }
        ans.push_back('0' + nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        k %= fact;
        fact = fact / nums.size();
        solve(k, fact, nums, ans);
    }

public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        solve(k - 1, fact, nums, ans);
    }
};

int main()
{

    return 0;
}