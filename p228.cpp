#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int a, b;
        int n = nums.size();
        a = nums[0];
        b = nums[0];
        vector<string> ans;

        int tempA = a;
        for (int i = 1; i < n; i++)
        {
            if (b == nums[i] - 1)
                b = nums[i];
            else
            {
                string s = to_string(a);
                if (a != b)
                    s += "->" + to_string(b);
                ans.push_back(s);
                a = nums[i];
                b = nums[i];
            }
        }
        string s = to_string(a);
        if (a != b)
            s += "->" + to_string(b);
        ans.push_back(s);

        return ans;
    }
};

int main()
{

    return 0;
}