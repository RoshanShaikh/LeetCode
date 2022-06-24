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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        vector<int> v;

        queue<TreeNode *> q;
        stack<TreeNode *> st;

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();

            if (!tmp)
            {
                ans.emplace_back(v);
                v.clear();
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                v.push_back(tmp->val);
                if (tmp->right)
                {
                    q.push(tmp->right);
                }

                if (tmp->left)
                {
                    q.push(tmp->left);
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}