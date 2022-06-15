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
    bool isPresent(TreeNode *&root, int &val)
    {
        if (!root)
            return false;
        else if (root->val == val)
            return true;
        else if (root->val < val)
            return isPresent(root->right, val);
        else
            return isPresent(root->left, val);
    }

    bool solve(TreeNode *&root, TreeNode *&curr, int &val)
    {
        if (!root)
            return false;
        int target = val - root->val;
        if (target != root->val && isPresent(root, target))
            return true;
        if (solve(root, curr->left, val))
            return true;
        else if (solve(root, curr->right, val))
            return true;
        return false;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        return solve(root, root, k);
    }
};

int main()
{
    return 0;
}