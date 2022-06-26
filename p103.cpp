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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;

        if (!root)
            return ans;

        q.push(root);

        bool lTor = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();

                v[lTor ? i : size - i - 1] = tmp->val;

                if (tmp->left)
                    q.push(tmp->left);

                if (tmp->right)
                    q.push(tmp->right);
            }
            lTor = !lTor;
            ans.push_back(v);
        }

        return ans;
    }
};
int main()
{

    return 0;
}