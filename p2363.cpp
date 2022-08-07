#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        vector<vector<int>> ans;
        map<int, int> mp;
        for (int i = 0; i < items1.size(); i++)
        {
            mp[items1[i][0]] += items1[i][1];
        }

        for (int i = 0; i < items2.size(); i++)
        {
            mp[items2[i][0]] += items2[i][1];
        }

        for (auto &&pr : mp)
        {
            ans.push_back({pr.first, pr.second});
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> a = {{1, 1}, {4, 5}, {3, 8}};
    vector<vector<int>> b = {{3, 1}, {1, 5}};

    a = Solution().mergeSimilarItems(a, b);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i][0] << " " << a[i][1] << endl;
    }

    return 0;
}