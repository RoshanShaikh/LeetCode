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
    unordered_map<int, int> map;
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &index, int inStart, int inEnd)
    {
        if (index == preorder.size() || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[index++]);

        int position = map[root->val];

        root->left = solve(preorder, inorder, index, inStart, position - 1);
        root->right = solve(preorder, inorder, index, position + 1, inEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int inStart = 0;
        int inEnd = inorder.size() - 1;

        int index = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        return solve(preorder, inorder, index, inStart, inEnd);
    }
};

int main()
{

    return 0;
}