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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
            return -1;

        return max(lh, rh) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }
};

int main()
{

    return 0;
}