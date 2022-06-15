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
    ListNode *reverseLL(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *tail = new ListNode(head->val);
        head = head->next;
        while (head)
        {
            tail = new ListNode(head->val, tail);
            head = head->next;
        }
        return tail;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *reverseHead = reverseLL(head);

        while (head && reverseHead)
        {
            if (head->val == reverseHead->val)
                return false;

            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
};

int main()
{

    return 0;
}