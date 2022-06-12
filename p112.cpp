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
    bool solve(TreeNode *root, int sum, int &target)
    {
        if (root == nullptr)
            return false;

        sum += target;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == target)
                return true;
            else
                return false;
        }
        if (solve(root->left, sum, target))
            return true;
        if (solve(root->right, sum, target))
            return true;
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        return solve(root, sum, targetSum);
    }
};

int main()
{

    return 0;
}