#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> map(26, 0);
        for (auto &&c : s)
        {
            map[c - 'a']++;
        }
        for (auto &&c : t)
        {
            map[c - 'a']--;
            if (map[c - 'a'] < 0)
                return false;
        }
        for (auto &&i : map)
        {
            if (i > 0)
                return false;
        }

        return true;
    }
};

int main()
{

    return 0;
}