#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.empty())
            return p.empty();
        bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*')
            return isMatch(s, p.substr(2, p.size() - 2)) || (firstMatch && isMatch(s.substr(1, s.size() - 1), p));
        else
            return firstMatch && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
    }
};

int main()
{
    cout << (Solution().isMatch("aabbs", "a*.*") ? "true" : "false");
    return 0;
}