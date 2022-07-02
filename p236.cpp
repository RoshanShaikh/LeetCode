#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    pair<bool, bool> solve(TreeNode *&root, TreeNode *&p, TreeNode *&q, TreeNode *&ans)
    {
        if (!root)
            return {false, false};
        pair<bool, bool> ret = {root == p, root == q};

        pair<bool, bool> left = solve(root->left, p, q, ans);
        ret = {left.first || ret.first, left.second || ret.second};

        if (!(ret.first && ret.second))
        {
            pair<bool, bool> right = solve(root->right, p, q, ans);
            ret = {right.first || ret.first, right.second || ret.second};
        }

        if (!ans && ret.first && ret.second)
        {
            ans = root;
        }
        return ret;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = nullptr;
        solve(root, p, q, ans);
        return ans;
    }
};

int main()
{

    return 0;
}