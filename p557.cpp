#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void reverseString(string s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start++], s[end--]);
        }
    }

public:
    string reverseWords(string s)
    {
        int start = 0;
        while (start < s.size())
        {
            int i = start;
            while (i < s.size() && s[i] == ' ')
                i++;
            reverseString(s, start, i - 1);
            start = i;
        }
    }
};

int main()
{

    return 0;
}