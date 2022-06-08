#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            swap(s[start++], s[end--]);
        }
    }
};

int main()
{

    return 0;
}