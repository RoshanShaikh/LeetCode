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
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int inStart, int inEnd)
    {
        if (index < 0 || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[index--]);
        int position = map[root->val];

        root->right = solve(inorder, postorder, index, position + 1, inEnd);
        root->left = solve(inorder, postorder, index, inStart, position - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int index = inorder.size() - 1;

        int inStart = 0;
        int inEnd = inorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        return solve(inorder, postorder, index, inStart, inEnd);
    }
};
int main()
{

    return 0;
}