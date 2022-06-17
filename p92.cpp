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
    ListNode *reverse(ListNode *&head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head->next || left == right)
            return head;

        head = new ListNode(-1001, head);

        ListNode *lpart = head;
        int i = 1;
        while (i < left)
        {
            i++;
            lpart = lpart->next;
        }
        ListNode *reverseTail = lpart->next;
        i = 0;
        ListNode *rpart = lpart;
        while (i < right - left + 1)
        {
            i++;
            rpart = rpart->next;
        }
        ListNode *curr = rpart->next;
        rpart->next = NULL;
        rpart = curr;
        lpart->next = reverse(reverseTail);
        reverseTail->next = rpart;

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

    ListNode *tail = Solution().reverseBetween(head, 2, 4);
    while (tail)
    {
        cout << tail->val << " ";
        tail = tail->next;
    }
    return 0;
}