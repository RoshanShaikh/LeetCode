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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (root->val == key)
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (root->left && root->right)
            {
                TreeNode *tmp = root->right;
                while (tmp->left)
                {
                    tmp = tmp->left;
                }

                root->val = tmp->val;

                root->right = deleteNode(root->right, tmp->val);
                return root;
            }
            else if (root->left)
            {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            else
            {
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

int main()
{

    return 0;
}