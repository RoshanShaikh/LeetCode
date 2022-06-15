#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int &n, int &k, vector<bool> &canBeSelected, vector<int> &selected, vector<vector<int>> &ans)
    {
        if (selected.size() == k)
        {
            ans.push_back(selected);
            return;
        }
        int size = selected.size();
        int index;
        if (size == 0)
            index = 1;
        else
            index = selected[size - 1];
        for (int i = index; i <= n; i++)
        {
            if (canBeSelected[i - 1])
            {
                selected.push_back(i);
                canBeSelected[i - 1] = false;
                solve(n, k, canBeSelected, selected, ans);
                canBeSelected[i - 1] = true;
                selected.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<bool> canBeSelected(n, true);
        vector<vector<int>> ans;
        vector<int> selected;
        solve(n, k, canBeSelected, selected, ans);
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v = Solution().combine(n, k);
    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}