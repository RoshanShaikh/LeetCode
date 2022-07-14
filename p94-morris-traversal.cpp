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
    void morrisTraversal(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        morrisTraversal(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}