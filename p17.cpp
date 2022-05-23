#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<char, vector<string>> map;

public:
    Solution()
    {
        map['2'] = {"a", "b", "c"};
        map['3'] = {"d", "e", "f"};
        map['4'] = {"g", "h", "i"};
        map['5'] = {"j", "k", "l"};
        map['6'] = {"m", "n", "o"};
        map['7'] = {"p", "q", "r", "s"};
        map['8'] = {"t", "u", "v"};
        map['9'] = {"w", "x", "y", "z"};
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        if (digits.size() == 1)
            return map[digits[0]];
        return crossProduct(digits[0], letterCombinations(digits.substr(1, digits.size() - 1)));
    }

    vector<string> crossProduct(char a, vector<string> str)
    {
        vector<string> ans;
        for (auto &&i : map[a])
        {
            for (auto &&j : str)
            {
                ans.push_back(i + j);
            }
        }
        return ans;
    }
};

int main()
{
    string digits;
    cin >> digits;
    vector<string> v = Solution().letterCombinations(digits);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}