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
    unordered_map<TreeNode *, int> depth;
    int maxdepth = -1;
    void dfs(TreeNode *&root, TreeNode *&parent)
    {
        if (!root)
            return;

        depth[root] = depth[parent] + 1;
        maxdepth = max(maxdepth, depth[root]);
        dfs(root->left, root);
        dfs(root->right, root);
    }

    TreeNode *solve(TreeNode *&root)
    {
        if (!root || maxdepth == depth[root])
            return root;

        TreeNode *left = solve(root->left);
        TreeNode *right = solve(root->right);

        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        depth[NULL] = -1;
        TreeNode *null = NULL;
        dfs(root, null);

        return solve(root);
    }
};

int main()
{

    return 0;
}