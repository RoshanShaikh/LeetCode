#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int, greater<string>> word_count;
        int n = messages.size();
        for (int i = 0; i < n; i++)
        {
            int word = countWords(messages[i]);
            word_count[senders[i]] += word;
        }
        int maxLen = 0;
        string sender = "";
        for (auto &&i : word_count)
        {
            if (i.second > maxLen)
            {
                maxLen = i.second;
                sender = i.first;
            }
        }
        return sender;
    }

    int countWords(string s)
    {
        int word = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                word++;
        }
        return word + 1;
    }
};

int main()
{
    map<string, int> map;
    string s = "roshan";
    map[s] = 0;
    return 0;
}