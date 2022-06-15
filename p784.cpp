#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void convert(string &s, int &index)
    {
        if (s[index] >= 'A' && s[index] <= 'Z')
            s[index] += 32;
        else
            s[index] -= 32;
    }
    void solve(string &s, vector<string> &ans, int index)
    {
        if (index == s.size())
        {
            ans.push_back(s);
            return;
        }
        solve(s, ans, index + 1);
        if (s[index] >= '0' && s[index] <= '9')
            return;
        convert(s, index);
        solve(s, ans, index + 1);
        convert(s, index);
    }

public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;
        solve(s, ans, 0);
        return ans;
    }
};

int main()
{

    return 0;
}