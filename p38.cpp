// "1"
// "11"
// "21"
// "1211"
// "111221"
// "312211"
// "13112221"
// "1113213211"
// "31131211131221"
// "13211311123113112211"
// "11131221133112132113212221"
// "3113112221232112111312211312113211"
// "1321132132111213122112311311222113111221131221"
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // string countAndSay(string &s)
    // {
    //     string ans = "";
    // }

public:
    string countAndSay(int n)
    {
        string ans = "1";
        string s;
        for (int i = 1; i < n; i++)
        {
            s = ans;
            ans = "";
            int count = 1;
            for (int i = 0; i < s.size() - 1; i++)
            {
                if (s[i] == s[i + 1])
                    count++;
                else
                {
                    ans += to_string(count) + s[i];
                    count = 1;
                }
            }
            ans += to_string(count) + s[s.size() - 1];
        }
        return ans;
    }
};

int main()
{
    for (int i = 0; i < 30; i++)
    {
        cout << i + 1 << "\n";
    }

    int n;
    Solution ob;
    string ans;
    while (true)
    {
        cin >> n;
        ans = ob.countAndSay(n);
        cout << ans << "\n";
    }

    return 0;
}