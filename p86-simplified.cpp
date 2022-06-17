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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smaller = new ListNode(-101);
        ListNode *larger = new ListNode(101);

        ListNode *l1 = smaller;
        ListNode *l2 = larger;

        while (head)
        {
            if (head->val < x)
            {
                l1->next = head;
                l1 = l1->next;
            }
            else
            {
                l2->next = head;
                l2 = l2->next;
            }

            head = head->next;
        }

        l1->next = larger->next;
        l2->next = NULL;
        l1 = smaller;
        smaller = smaller->next;

        delete l1;
        delete larger;
        
        return smaller;
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