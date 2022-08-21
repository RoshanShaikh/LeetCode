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
    TreeNode *lca(TreeNode *&root, TreeNode *&p, TreeNode *&q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->left, p, q);

        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> prev;
        vector<TreeNode *> lastLevel;
        queue<TreeNode *> curr;

        prev.push(root);

        while (!prev.empty())
        {
            int size = prev.size();
            lastLevel.clear();
            while (size--)
            {
                TreeNode *tmp = prev.front();
                prev.pop();
                lastLevel.push_back(tmp);

                if (tmp->left)
                    curr.push(tmp->left);

                if (tmp->right)
                    curr.push(tmp->right);
            }

            if (curr.empty())
            {
                break;
            }
            prev = curr;
            while (!curr.empty())
            {
                curr.pop();
            }
        }

        TreeNode *ans = lastLevel[0];

        if (lastLevel.size() > 1)
        {
            ans = lca(root, ans, lastLevel[lastLevel.size() - 1]);
        }

        return ans;
    }
};

int main()
{
    queue<int> a;
    queue<int> b;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);

    b = a;
    while (!a.empty())
    {
        a.pop();
    }

    cout << "b:";
    while (!b.empty())
    {
        cout << b.front() << " ";
        b.pop();
    }
    cout << "a:";
    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }

    return 0;
}