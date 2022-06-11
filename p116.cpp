#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
    void solve(Node *root, Node *next)
    {
        if (root == NULL)
            return;
        root->next = (next != nullptr) ? next->left : next;
        solve(root->left, root->right);
        solve(root->right, root->next);
    }

public:
    Node *connect(Node *root)
    {
        solve(root, nullptr);
        return root;
    }
};

int main()
{

    return 0;
}