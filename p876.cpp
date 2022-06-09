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
    ListNode *middleNode(ListNode *head)
    {
        int n = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            n++;
            curr = curr->next;
        }
        int mid = n / 2 + 1;
        curr = head;
        n = 0;
        while (n < mid)
        {
            curr = curr->next;
            n++;
        }
        return curr;
    }
};

int main()
{

    return 0;
}