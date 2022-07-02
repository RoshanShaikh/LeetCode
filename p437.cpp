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
    void solve(TreeNode *&root, int &targetSum, int &ans, vector<int> &path)
    {
        if (!root)
            return;

        path.push_back(root->val);

        solve(root->left, targetSum, ans, path);

        solve(root->right, targetSum, ans, path);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == targetSum)
                ans++;
        }

        path.pop_back();
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        int ans = 0;
        solve(root, targetSum, ans, path);
        return ans;
    }
};

int main()
{

    return 0;
}