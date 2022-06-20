#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        vector<pair<bool, bool>> map(26, pair<bool, bool>{false, false});

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                map[s[i] - 'A'].first = true;
            else
                map[s[i] - 'a'].second = true;
        }
        string ans = "";
        for (int i = 25; i >= 0; i--)
        {
            if (map[i].first && map[i].second)
            {
                ans.push_back('A' + i);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    cout << char('A' + 5);

    Solution ob;
    while (true)
    {
        string s;
        cin >> s;
        cout << ob.greatestLetter(s) << endl;
    }

    return 0;
}