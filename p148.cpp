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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        if (left->val > right->val)
            swap(left, right);

        ListNode *ans = left;

        ListNode *leftNext = left->next;
        ListNode *rightNext = right->next;

        while (leftNext && right)
        {
            if (right->val >= left->val && right->val <= leftNext->val)
            {
                right->next = leftNext;
                left->next = right;
                left = right;
                right = rightNext;
            }
            else
            {
                left = leftNext;
                leftNext = left->next;
            }
        }
        if (right)
        {
            left->next = right;
        }
        return left;
    }

    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};

int main()
{

    return 0;
}