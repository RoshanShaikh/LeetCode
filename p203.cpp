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
    ListNode *removeElements(ListNode *head, int val)
    {
        head = new ListNode(-101, head);
        ListNode *ans = head;
        ListNode *current = head->next;
        ListNode *prev = head;

        while (current != nullptr)
        {
            ListNode *next = current->next;
            if (current->val == val)
            {
                delete(current);
                prev->next = next;
            }
            else
                prev = prev->next;
            current = next;
        }
        return ans->next;

        // while (ans != nullptr && ans->val == val)
        // {
        //     ListNode *next = ans->next;
        //     delete (ans);
        //     ans = next;
        // }
        // ListNode *current = ans;
        // while (current != nullptr && current->next != nullptr)
        // {
        //     while (current->next != nullptr && current->next->val == val)
        //     {
        //         ListNode *next = current->next->next;
        //         delete (current->next);
        //         current->next = next;
        //     }
        //     current = current->next;
        // }

        // return ans;
    }
};

int main()
{

    return 0;
}