#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> freq;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }

        unordered_set<int> seen;

        int deleteCount = 0;

        for (auto &&mp : freq)
        {
            while (mp.second && !seen.insert(mp.second).second)
            {
                deleteCount++;
                mp.second--;
            }
        }

        return deleteCount;
    }
};

int main()
{

    return 0;
}