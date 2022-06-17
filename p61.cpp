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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;

        ListNode *curr = head;
        int len = 1;
        while (curr->next->next)
        {
            len++;
            curr = curr->next;
        }
        len++;

        k %= len;

        curr->next->next = head;
        curr = head;

        for (int i = 1; i < len - k; i++)
        {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = NULL;

        return head;
    }
};

int main()
{

    return 0;
}