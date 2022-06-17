#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int>> map;

        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(i);
        }

        vector<vector<string>> ans(map.size());
        int i = 0;
        for (auto &&it : map)
        {
            vector<int> &v = it.second;
            for (auto &&ind : v)
            {
                ans[i].push_back(strs[ind]);
            }
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}