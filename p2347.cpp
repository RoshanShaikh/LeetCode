#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        unordered_map<char, int> s;

        for (int i = 0; i < 5; i++)
        {
            s[suits[i]]++;
        }

        for (auto mp : s)
        {
            if (mp.second == 5)
                return "Flush";
            else
                break;
        }

        unordered_map<int, int> r;

        for (int i = 0; i < 5; i++)
        {
            r[ranks[i]]++;
        }

        string ans = "High Card";

        for (auto mp : r)
        {
            if (mp.second >= 3)
                ans = "Three of a Kind";
            else if (mp.second >= 2 && ans == "High Card")
                ans = "Pair";
        }

        return ans;
    }
};

int main()
{

    return 0;
}