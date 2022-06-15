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
    ListNode *reverseKGroup(ListNode *&head, int &k)
    {
        if (!head)
            return head;

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;

        int count = 0;
        while (curr && count < k)
        {
            curr = curr->next;
            count++;
        }
        if (count < k)
            return head;
        count = 0;
        curr = head;
        while (curr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (curr)
        {
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};

int main()
{

    return 0;
}