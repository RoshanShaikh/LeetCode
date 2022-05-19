#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        string str = to_string(x);
        if (str[0] == '-')
            std::reverse(str.begin() + 1, str.end());
        else
            std::reverse(str.begin(), str.end());

        if (stoi(str) > INT_MAX && stoi(str) < INT_MIN)
            return 0;
        else
            return stoi(str);
    }
};

int main()
{
    cout << Solution().reverse(-210);
    return 0;
}