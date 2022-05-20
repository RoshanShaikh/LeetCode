#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<string, int> map;
        map["I"] = 1;
        map["V"] = 5;
        map["X"] = 10;
        map["L"] = 50;
        map["C"] = 100;
        map["D"] = 500;
        map["M"] = 1000;
        int i = s.size() - 1;
        int ans = map[s.substr(i, 1)];
        i--;
        while (i >= 0)
        {
            int val = map[s.substr(i, 1)];
            if (val < map[s.substr(i + 1, 1)])
                ans -= val;
            else
                ans += val;
        }
        return ans;
    }
};

int main()
{

    return 0;
}