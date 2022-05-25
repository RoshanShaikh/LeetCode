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
    ListNode *swapPairs(ListNode *head)
    {
        head = new ListNode(-1, head);
        if (head->next == nullptr)
            return nullptr;
        if (head->next->next == nullptr)
            return head->next;
        // ListNode *tmp1 = head->next;
        // ListNode *tmp2 = head->next->next;
        // head->next = tmp2;
        // tmp1->next = tmp2->next;
        // tmp2->next = tmp1;
        // tmp1->next =
        //     swapPairs(tmp1->next);
        // return head->next;
        ListNode *current = head;
        while (current->next != nullptr && current->next->next != nullptr)
        {
            ListNode *tmp1 = current->next;
            ListNode *tmp2 = current->next->next;
            current->next = tmp2;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            current = tmp1;
        }
        return head->next;
    }
};

int main()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode();
    ListNode *current = head;
    for (int j = 0; j < n; j++)
    {
        int tmp;
        cin >> tmp;
        current->next = new ListNode(tmp);
        current = current->next;
    }
    head = head->next;
    ListNode *ans = Solution().swapPairs(head);
    while (ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}