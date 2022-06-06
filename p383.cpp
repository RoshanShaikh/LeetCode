#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> map(26, 0);
        for (auto &&c : magazine)
        {
            map[c - 'a']++;
        }
        for (auto &&c : ransomNote)
        {
            map[c-'a']--;
            if (map[c] < 0)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}