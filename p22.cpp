#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    void backtrack(vector<string> &ans, string current, int open, int close, int max)
    {
        if (current.size() == max * 2)
        {
            ans.push_back(current);
            return;
        }

        if (open < max)
            backtrack(ans, current + "(", open + 1, close, max);
        if (close < open)
            backtrack(ans, current + ")", open, close + 1, max);
    }
};

int main()
{
    vector<string> v = Solution().generateParenthesis(4);
    for (auto &&i : v)
    {
        cout << i << endl;
    }

    return 0;
}
