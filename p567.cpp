#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool matches(unordered_map<char, int> &s1, unordered_map<char, int> &s2)
    {
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        unordered_map<char, int> map;
        unordered_map<char, int> tmpMap;
        for (int i = 0; i < n; i++)
        {
            map[s1[i]]++;
            tmpMap[s2[i]]++;
        }
        for (int i = 1; i < m - n + 1; i++)
        {
            if (matches(map, tmpMap))
                return true;
            tmpMap[s2[i + n - 1]]++;
            tmpMap[s2[i - 1]]--;
        }
        return matches(map, tmpMap);
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << (Solution().checkInclusion(s1, s2) ? "true" : "false");
    return 0;
}