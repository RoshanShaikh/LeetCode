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

// Uncomplete
class Solution
{
    void countNodesAtOddlevel(TreeNode *root, int level, int &count)
    {
        if (!root)
            return;
        if (root->left)
        {
            if (level % 2 == 0)
                count++;
            countNodesAtOddlevel(root->left, level + 1, count);
        }
        if (root->right)
        {
            if (level % 2 == 0)
                count++;
            countNodesAtOddlevel(root->right, level + 1, count);
        }
    }

public:
    int minCameraCover(TreeNode *root)
    {
        if (!root->right && !root->left)
            return 1;
        int count1 = 0;
        if (root->right)
        {
            countNodesAtOddlevel(root->left, 0, count1);
            count1++;
            countNodesAtOddlevel(root->right, 1, count1);
        }
        int count2 = 0;
        if (root->left)
        {
            count2++;
            countNodesAtOddlevel(root->left, 1, count2);
            countNodesAtOddlevel(root->right, 0, count2);
        }
        if (count1 == 0)
            count1++;
        if (count2 == 0)
            count2++;

        cout << count1 << " " << count2 << "\n";
        return min(count1, count2);
    }
};

int main()
{

    return 0;
}