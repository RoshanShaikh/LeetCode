#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        sort(
            words.begin(), words.end(),
            [](const string &first,
               const string &second)
            { return first.length() > second.length(); });

        string ans = "";

        for (auto &&str : words)
        {
            if (ans.find(str+"#") == string::npos)
                ans += str + '#';
        }

        return ans.size();
    }
};

int main()
{
    vector<string> words = {"feipyxx", "e"};
    cout << Solution().minimumLengthEncoding(words);

    return 0;
}