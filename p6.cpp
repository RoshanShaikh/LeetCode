#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // int n = s.size();
        // string ans = "";
        // int gap = numRows * 2 - 2;
        // for (int i = 0; i < numRows; i++)
        // {
        //     int k = i;
        //     while (k < n)
        //     {
        //         ans += s[k];
        //         if (i != 0 && i != numRows - 1)
        //         {
        //             int mid = k + (numRows - i - 1) * 2;
        //             if (mid < n)
        //                 ans += s[mid];
        //         }
        //         k += gap;
        //     }
        // }

        int n = s.size();
        if (numRows == 1)
            return s;

        int step = 1, row = 0;
        string str[numRows];
        for (int i = 0; i < n; i++)
        {
            str[row].push_back(s[i]);
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }

        s.clear();
        for (auto &&str : str)
        {
            s.append(str);
        }

        return s;
    }
};

int main()
{
    cout << Solution().convert("ABCD", 2);
    return 0;
}