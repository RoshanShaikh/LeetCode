#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static inline vector<string> charMap = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> set;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            string morseCode = "";

            for (int i = 0; i < word.size(); i++)
            {
                morseCode += charMap[word[i] - 'a'];
            }
            set.insert(morseCode);
        }

        return set.size();
    }
};

int main()
{

    return 0;
}