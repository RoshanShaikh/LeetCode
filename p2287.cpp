#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> smap;
        for (int i = 0; i < s.size(); i++)
        {
            smap[s[i]]++;
        }
        unordered_map<char, int> tmap;
        for (int i = 0; i < target.size(); i++)
        {
            tmap[target[i]]++;
        }

        bool increase = true;
        int ans = 0;
        while (true)
        {
            for (auto &&i : tmap)
            {
                if (smap[i.first] < i.second)
                {
                    increase = false;
                    break;
                }
                else
                    smap[i.first] -= i.second;
            }
            if (increase)
                ans++;
            else
                break;
        }
        return ans;
    }
};

int main()
{

    return 0;
}