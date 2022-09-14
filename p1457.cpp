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
    bool checkCanBePalindrome(vector<int> &nums, vector<int> &freq)
    {
        int n = nums.size();

        int odd = 0, even = 0;

        for (int i = 0; i < 10; i++)
        {
            if (freq[i] == 0)
                continue;
            else if (freq[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        if (n % 2 == 0 && odd > 0)
            return false;

        if (n % 2 == 1 && odd > 1)
            return false;

        return true;
    }

    void solve(TreeNode *root, vector<int> &nums, int &ans, vector<int> &freq)
    {
        if (!root)
            return;

        nums.push_back(root->val);
        freq[root->val]++;

        if (!root->left && !root->right)
        {
            if (checkCanBePalindrome(nums, freq))
                ans++;
            freq[root->val]--;
            nums.pop_back();
            return;
        }

        solve(root->left, nums, ans, freq);
        solve(root->right, nums, ans, freq);
        freq[root->val]--;
        nums.pop_back();
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int ans = 0;
        vector<int> nums;
        vector<int> freq(10, 0);
        solve(root, nums, ans, freq);
        return ans;
    }
};

int main()
{
    return 0;
}