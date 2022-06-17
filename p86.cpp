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
    ListNode *findLess(ListNode *head, int x)
    {
        ListNode *curr = head;
        while (curr->next)
        {
            if (curr->next->val < x)
                return curr;
            curr = curr->next;
        }
        return NULL;
    }

public:
    ListNode *partition(ListNode *head, int x)
    {
        head = new ListNode(-101, head);
        ListNode *curr = head;
        ListNode *less = head;
        ListNode *lesspoint = head;

        while (curr->next)
        {
            if (curr->val < x && curr->next->val >= x)
            {
                less = findLess(less, x);
                if (!less)
                    break;
                lesspoint = less->next;
                less->next = lesspoint->next;
                lesspoint->next = curr->next;
                curr->next = lesspoint;
            }
            else
            {
                curr = curr->next;
                less = curr;
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

    ListNode *tail = Solution().partition(head, 3);
    while (tail)
    {
        cout << tail->val << " ";
        tail = tail->next;
    }
    return 0;
}