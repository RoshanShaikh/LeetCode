#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool digitCount(string num)
    {
        int n = num.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[i] != num[i])
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}