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
    bool solve(TreeNode *&root, long minVal, long maxVal)
    {
        if (!root)
            return true;
        if (root->val >= maxVal || root->val <= minVal)
            return false;
        return solve(root->left, minVal, root->val) && solve(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};

int main()
{

    return 0;
}