#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++)
        {
            vector<bool> taken(26, false);
            string word = words[i];

            unordered_map<char, char> map;
            for (int j = 0; j < word.size(); j++)
            {
                if (!map.count(pattern[j]))
                {
                    if (taken[word[j] - 'a'])
                        break;
                    else
                    {
                        map[pattern[j]] = word[j];
                        taken[word[j] - 'a'] = true;
                    }
                }
                else if (map[pattern[j]] != word[j])
                    break;

                if (j == word.size() - 1)
                    ans.push_back(word);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}