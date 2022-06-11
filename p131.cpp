#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPelindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void solve(int index, string &s, vector<string> &seqs, vector<vector<string>> &result)
    {
        if (index == s.size())
        {
            result.push_back(seqs);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPelindrome(s, index, i))
            {
                seqs.push_back(s.substr(index, i - index + 1));
                solve(index + 1, s, seqs, result);
                seqs.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> seqs;
        solve(0, s, seqs, result);
        return result;
    }
};
int main()
{

    return 0;
}