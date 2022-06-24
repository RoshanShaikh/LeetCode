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

        st.push(root);
        st.push(NULL);

        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();

            if (!tmp)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                    st.push(NULL);
                }
            }
            else
            {
                if (tmp->right)
                {
                    st.push(tmp->right);
                    q.push(tmp->right);
                }

                if (tmp->left)
                {
                    q.push(tmp->left);
                    st.push(tmp->left);
                }
            }
        }

        while (!st.empty())
        {
            TreeNode *tmp = st.top();
            st.pop();

            while (tmp)
            {
                v.push_back(tmp->val);
                if (!st.empty())
                {
                    tmp = st.top();
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            if (!v.empty())
                ans.push_back(v);
            v.clear();
        }

        return ans;
    }
};

int main()
{

    return 0;
}