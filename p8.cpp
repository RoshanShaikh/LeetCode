#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        cout << INT_MAX << " " << INT_MIN;
        int n = s.size();
        int i = 0;
        int val = +1;
        while (s[i] == ' ')
            i++;
        if (s[i] == '-')
        {
            val = -1;
            i++;
        }
        else if (s[i])
        {
            val = +1;
            i++;
        }
        long ans = 0;
        while (i < n)
        {
            if (!isdigit(s[i]))
                return ans;
            ans = ans * 10 + stol(s.substr(i, 1));
            if (ans * val > INT_MAX)
            {
                ans = INT_MAX;
                break;
            }
            else if (ans * val < INT_MIN)
            {
                ans = INT_MIN;
                break;
            }
        }
        return ans; 
    }
};

int main()
{
    return 0;
}