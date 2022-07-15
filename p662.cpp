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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;
        queue<pair<TreeNode *, unsigned>> q;
        q.push({root, 0});
        int first, last;
        while (!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second;
            for (int i = 0; i < size; i++)
            {
                int curr_idx = q.front().second - mmin;

                TreeNode *tmp = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr_idx;
                if (i == size - 1)
                    last = curr_idx;

                if (tmp->left)
                    q.push({tmp->left, curr_idx * 2 + 1});

                if (tmp->right)
                    q.push({tmp->right, curr_idx * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}