#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static string longestPalindrome(string s)
    {
        string result;
        for (int i = 0; i < s.size(); i++)
        {
            checkPelin(s, result, i, i);
            checkPelin(s, result, i, i + 1);
        }
        return result;
    }

    static void checkPelin(string s, string &result, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > result.length())
            {
                result = s.substr(left, right - left + 1);
            }
            left--;
            right++;
        }
    }
};

int main()
{
    cout << Solution::longestPalindrome("a");
    return 0;
}