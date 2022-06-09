#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void combinationSum2(int index, vector<int> &candidates, int target, vector<int> &seq, vector<vector<int>> &ans)
    {
        if (index == candidates.size())
        {
            if (target == 0)
                ans.push_back(seq);
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                break;
            seq.push_back(candidates[i]);
            combinationSum2(index + 1, candidates, target - candidates[i], seq, ans);
            seq.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> seq;
        combinationSum2(0, candidates, target, seq, ans);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    int k;
    cin >> k;
    vector<vector<int>> ans = Solution().combinationSum2(in, k);
    for (auto &&list : ans)
    {
        for (auto &&ele : list)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}