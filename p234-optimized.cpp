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
    ListNode *reverseLL(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = head;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *midNode = middleNode(head);
        ListNode *reverseNode = reverseLL(midNode->next);

        while (head && reverseNode)
        {
            if (head->val != reverseNode->val)
                return false;
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    ListNode *head = NULL;
    while (n--)
    {
        int c;
        cin >> c;
        head = new ListNode(c, head);
    }

    ListNode *mid = Solution().middleNode(head);
    return 0;
}