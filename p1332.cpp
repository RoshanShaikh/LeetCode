#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPelin(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j++])
                return false;
        }
        return true;
    }

public:
    int removePalindromeSub(string s)
    {
        if (s.empty())
            return 0;
        if (isPelin(s))
            return 1;
        return 2;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().removePalindromeSub(s);
    return 0;
}