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
    TreeNode *solve(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
            return root;

        TreeNode *head = root;
        TreeNode *right = root->right;

        root->right = solve(root->left);
        root->left = NULL;

        while (root->right)
            root = root->right;

        root->right = solve(right);

        return head;
    }

public:
    void flatten(TreeNode *root)
    {
        solve(root);
    }
};

int main()
{

    return 0;
}