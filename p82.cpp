#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        head = new ListNode(-101, head);

        int prevDelete = -101;

        ListNode *curr = head;

        while (curr->next)
        {
            if (curr->next->val == prevDelete ||
                (curr->next->next && curr->next->next->val == curr->next->val))
            {
                prevDelete = curr->next->val;
                ListNode *tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head->next;
    }
};

int main()
{

    int n;
    cin >> n;
    int c;
    cin >> c;
    n--;
    ListNode *head = new ListNode(c);
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        head = new ListNode(c, head);
    }

    Solution().deleteDuplicates(head);
    return 0;
}