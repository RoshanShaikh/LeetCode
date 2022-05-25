#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.size(); i++)
        {
            int j = 0, k = i;
            bool flag = true;
            while (j < needle.size() && k < haystack.size())
            {
                if (haystack[k] != needle[j])
                {
                    flag = false;
                    break;
                }
                k++;
                j++;
            }
            if (flag)
                return i;
        }
        return -1;
    }
};

int main()
{

    return 0;
}