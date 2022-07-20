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
    int solve(TreeNode *&root, int &ans)
    {

        if (!root)
            return 0;

        int left = max(0, solve(root->left,ans));
        int right = max(0, solve(root->right,ans));

        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}