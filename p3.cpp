#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        // Basic Approach

        /*
        unsigned int longestNo = 0, start = 0;
        string currentString = "";
        for (unsigned int i = 0; i < s.length(); i++)
        {
            if (currentString.find(s[i]) == string::npos)
            {
                currentString += s[i];
                if (currentString.length() > longestNo)
                    longestNo = (longetsNo,currentString.length());
            }
            else
            {
                unsigned int pos = currentString.find(s[i]);
                currentString.erase(0, pos + 1);
                currentString = currentString + s[i];
            }
            cout << currentString << " ";
            cout << i << " ";
        }
        return longestNo;
        */

        // Using Set

        /*
        unsigned int longestNo = 0, start = 0, end = 0;
        set<char> charSet;
        for (end = 0; end < s.length(); end++)
        {
            while (charSet.find(s[end]) != charSet.end())
            {
                charSet.erase(s[start++]);
            }
            charSet.insert(s[end]);
            longestNo = max(longestNo, end - start + 1);
        }
        return longestNo;
        */

        // Using Map

        /*
        unsigned longestNo = 0;
        unordered_map<char, unsigned> map;
        unsigned start = 0, end = 0;
        for (end = 0; end < s.size(); end++)
        {
            if (map.find(s[end]) != map.end())
            {
                start = max(start, map[s[end]] + 1);
            }
            map[s[end]] = end;
            longestNo = max(longestNo, end - start + 1);
        }
        return longestNo;
        */
    }
};

int main()
{
    cout << (Solution::lengthOfLongestSubstring("abba"));
    return 0;
}