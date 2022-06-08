#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // TC = O(n) SC = O(n)
        /*
        unordered_set<ListNode *> s;
        while (true)
        {
            if (head == nullptr)
                return false;
            if (!s.insert(head).second)
                return true;
            head = head->next;
        }
        return true;
        */
        // TC = O(n) SC = O(1)
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}