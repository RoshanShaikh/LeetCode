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
    class Solution
    {
    public:
        ListNode *deleteDuplicates(ListNode *head)
        {
            if (head == nullptr || head->next == nullptr)
                return head;
            ListNode *prev = head;
            ListNode *curr = head->next;
            while (curr != nullptr)
            {
                if (prev->val == curr->val)
                {
                    ListNode *tmp = curr->next;
                    delete (curr);
                    curr = tmp;
                    prev->next = curr;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            return head;
        }
    };
};

int main()
{

    return 0;
}