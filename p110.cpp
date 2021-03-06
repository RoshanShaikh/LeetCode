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
    pair<bool, int> solve(TreeNode *root)
    {
        if (!root)
            return {true, 0};

        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);

        return {left.first && right.first && abs(left.second - right.second) <= 1, max(left.second, right.second) + 1};
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return solve(root).first;
    }
};

int main()
{

    return 0;
}