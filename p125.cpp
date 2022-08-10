#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // string s1 = "";

        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (isalnum(s[i]))
        //     {
        //         s1 += tolower(s[i]);
        //     }
        // }

        int i = 0, j = s.size() - 1;
        while (!isalnum(s[i]) && i < j)
        {
            i++;
        }
        while (!isalnum(s[j]) && i < j)
        {
            j--;
        }
        while (i < j && tolower(s[i]) == tolower(s[j]))
        {
            do
            {
                i++;
            } while (!isalnum(s[i]) && i < j);
            do
            {
                j--;
            } while (!isalnum(s[j]) && i < j);
        }
        if (i >= j)
            return true;
        return false;
    }
};

int main()
{
    cout << (Solution().isPalindrome("A man, a plan, a canal: Panama ") ? "true" : "false");
    return 0;
}