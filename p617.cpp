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
    void solve(TreeNode *r1, TreeNode *r2, TreeNode *ans)
    {
        if (r1 != nullptr && r2 != nullptr)
        {
            ans = new TreeNode(r1->val + r2->val);
            solve(r1->left, r2->left, ans->left);
            solve(r1->right, r2->right, ans->right);
        }
        else if (r1 != nullptr)
        {
            ans = new TreeNode(r1->val);
            solve(r1->left, r2, ans->left);
            solve(r1->right, r2, ans->right);
        }
        else if (r2 != nullptr)
        {
            ans = new TreeNode(r2->val);
            solve(r1, r2->left, ans->left);
            solve(r1, r2->right, ans->right);
        }
    }

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // TreeNode *ans;
        // solve(root1, root2, ans);
        // return ans;

        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

int main()
{

    return 0;
}