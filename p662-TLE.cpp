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
    int heightOfBT(TreeNode *root)
    {
        if (!root)
            return 0;

        return max(heightOfBT(root->left), heightOfBT(root->right)) + 1;
    }

    void addNodes(TreeNode *root, int cur, int &height)
    {
        if (cur == height)
        {
            return;
        }

        if (!root->left)
            root->left = new TreeNode(101);

        addNodes(root->left, cur + 1, height);

        if (!root->right)
            root->right = new TreeNode(101);

        addNodes(root->right, cur + 1, height);
    }

    vector<vector<int>> lastLevelElements(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode *tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if (tmp->left)
                {
                    q.push(tmp->left);
                }
                if (tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }

public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int height = heightOfBT(root);
        addNodes(root, 1, height);
        vector<vector<int>> lle = lastLevelElements(root);
        int ans = INT_MIN;
        int i, s;
        for (int j = lle.size() - 1; j >= 0; j--)
        {
            vector<int> v = lle[j];
            i = 0;
            while (i < v.size() && v[i] == 101)
                i++;

            s = i;
            i = v.size() - 1;
            while (i >= 0 && v[i] == 101)
                i--;

            ans = max(ans, i - s + 1);
        }

        return ans;
    }
};

int main()
{

    TreeNode *three = new TreeNode(3);
    TreeNode *two = new TreeNode(2, three, nullptr);
    TreeNode *root = new TreeNode(1, two, nullptr);
    cout << Solution().widthOfBinaryTree(root);
    return 0;
}