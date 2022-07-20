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
    TreeNode *searchBST(TreeNode *&root, int &val)
    {
        if (!root)
            return root;
        if (root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        return nullptr;
    }

    TreeNode *searchBstIteratively(TreeNode *root, int &val)
    {
        while (root && root->val != val)
        {
            if (val < root->val)
                root = root->left;
            else if (val > root->val)
                root = root->right;
        }
        return root;
    }
};

int main()
{

    return 0;
}