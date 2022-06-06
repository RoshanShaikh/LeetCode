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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // TC = O(mn) SC = O(1)
        /*
        ListNode *a = headA;
        while (a != nullptr)
        {
            ListNode *b = headB;
            while (b != nullptr)
            {
                if (a == b)
                {
                    return a;
                }
                b = b->next;
            }
            a = a->next;
        }
        */
        // TC = O(m + n) SC = O(m+n)
        /*
        vector<ListNode *> a;
        while (headA != nullptr)
        {
            a.push_back(headA);
            headA = headA->next;
        }
        a.push_back(nullptr);
        vector<ListNode *> b;
        while (headB != nullptr)
        {
            b.push_back(headB);
            headB = headB->next;
        }
        b.push_back(nullptr);
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0 && a[i] == b[j])
        {
            i--;
            j--;
        }

        return a[++i];
        */
        // TC - O(m+n) SC - O(1)
        ListNode *a = headA;
        ListNode *b = headB;
        int n = 0;
        while (a->next)
        {
            n++;
            a = a->next;
        }
        n++;
        int m = 0;
        while (b->next)
        {
            m++;
            b = b->next;
        }
        if (a != b)
            return nullptr;
        m++;
        while (n > m)
        {
            headA = headA->next;
            n--;
        }
        while (m > n)
        {
            headB = headB->next;
            m--;
        }
        while (headB != headA)
        {
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }
};

int main()
{

    return 0;
}