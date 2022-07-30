#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool checkSubset(string a, unordered_map<char, int> freq, int n)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (freq[a[i]] > 0)
            {
                freq[a[i]]--;
                n--;
            }
        }

        if (n > 0)
            return false;

        return true;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> freq;
        for (int i = 0; i < words2.size(); i++)
        {
            unordered_map<char, int> map;
            for (auto &&c : words2[i])
            {
                map[c]++;
                freq[c] = max(freq[c], map[c]);
            }
        }
        int n = 0;
        for (auto &&mp : freq)
        {
            n += mp.second;
        }

        vector<string> ans;
        for (int i = 0; i < words1.size(); i++)
        {
            if (checkSubset(words1[i], freq, n))
            {
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}