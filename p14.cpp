#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         string ans = "";
//         int n = strs[0].length();
//         char first = strs[0][0];
//         for (auto &&i : strs)
//         {
//             if (i[0] != first)
//                 return ans;
//             if (i.size() < n)
//             {
//                 n = i.size();
//                 ans = i;
//             }
//         }
//         for (auto x : strs)
//         {
//             int i = 0, j = 0;
//             while (i < x.size() && j < ans.size())
//             {
//                 if (x[i] != ans[j])
//                     break;
//                 i++;
//                 j++;
//             }
//             ans = ans.substr(0,i);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    string longestCommonPrefix(vector<string> &strs, int l, int r)
    {
        if (l == r)
            return strs[l];
        int mid = (l + r) / 2;
        string lprefix = longestCommonPrefix(strs, l, mid);
        string rprefix = longestCommonPrefix(strs, mid + 1, r);
        return commonPrefix(lprefix, rprefix);
    }
    string commonPrefix(string left, string right)
    {
        int min = std::min(left.size(), right.size());
        int i = 0;
        string prefix = "";
        while (i < min)
        {
            if (left[i] != right[i])
                return prefix;
            prefix += left[i];
            i++;
        }
        return prefix;
    }
};

int main()
{

    return 0;
}