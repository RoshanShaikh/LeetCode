#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool checkValid(string num, string pattern)
    {
        for (int i = 0; i < pattern.size(); i++)
        {
            if (pattern[i] == 'I' && num[i] > num[i + 1])
                return false;
            else if (pattern[i] == 'D' && num[i] < num[i + 1])
                return false;
        }

        return true;
    }

    bool generateNums(string &num, string &pattern, int &index, vector<bool> &taken, string &ans)
    {
        if (index == pattern.size() + 1)
        {
            if (checkValid(num, pattern))
            {
                ans = num;
                return true;
            }
            return false;
        }
        index++;
        for (int i = 1; i < 10; i++)
        {
            if (!taken[i])
            {
                taken[i] = true;
                num.push_back('0' + i);
                if (generateNums(num, pattern, index, taken, ans))
                    return true;
                taken[i] = false;
                num.pop_back();
            }
        }
        index--;
        return false;
    }

public:
    string smallestNumber(string pattern)
    {
        vector<bool> taken(10, false);
        int index = 0;
        string num = "";
        string ans;
        generateNums(num, pattern, index, taken, ans);

        return ans;
    }
};

int main()
{
    cout << Solution().smallestNumber("IID");
    return 0;
}