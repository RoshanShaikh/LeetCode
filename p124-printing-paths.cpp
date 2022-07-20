#include <bits/stdc++.h>
using namespace std;

// Path is not in order

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
    pair<int, vector<int>> solve(TreeNode *&root, int &ans, vector<int> &path)
    {

        if (!root)
            return {0, {}};

        pair<int, vector<int>> leftPair = solve(root->left, ans, path);
        pair<int, vector<int>> rightPair = solve(root->right, ans, path);

        int left = leftPair.first;
        int right = rightPair.first;

        vector<int> leftPath = leftPair.second;
        vector<int> rightPath = rightPair.second;

        if (left < 0)
        {
            left = 0;
            leftPath.clear();
        }
        if (right < 0)
        {
            right = 0;
            rightPath.clear();
        }

        int sum = left + right + root->val;
        if (sum > ans)
        {
            ans = sum;
            path = leftPath;
            path.push_back(root->val);
            for (auto &&i : rightPath)
            {
                path.emplace_back(i);
            }
        }

        if (left >= right)
        {
            leftPath.push_back(root->val);
            return {left + root->val, leftPath};
        }
        else
        {
            reverse(rightPath.begin(), rightPath.end());
            rightPath.insert(rightPath.end(), root->val);
            return {right + root->val, rightPath};
        }
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        vector<int> path;
        solve(root, ans, path);
        for (auto i : path)
        {
            cout << i << endl;
        }
        cout << "Finished\n\n";
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution().maxPathSum(root);
    return 0;
}