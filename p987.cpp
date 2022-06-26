#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> map;

        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> tmp = q.front();
            q.pop();

            TreeNode *frontNode = tmp.first;
            int hd = tmp.second.first;
            int level = tmp.second.second;

            map[hd][level].push_back(frontNode->val);

            if (frontNode->left)
                q.push({frontNode->left, {hd - 1, level + 1}});
            if (frontNode->right)
                q.push({frontNode->right, {hd + 1, level + 1}});
        }

        vector<vector<int>> ans;

        for (auto &&mp : map)
        {
            vector<int> v;
            for (auto &&j : mp.second)
            {
                for (auto &&k : j.second)
                {
                    v.push_back(k);
                }
            }
            ans.emplace_back(v);
        }

        return ans;
    }
};

int main()
{
    map<int, vector<int>> mp;
    for (int i = 10; i >= 1; i--)
        mp[i % 3].push_back(i);

    for (auto &&i : mp)
    {
        cout << i.first << "--->";
        for (auto &&j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}