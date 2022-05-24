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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        list1 = new ListNode(-101, list1);
        list2 = new ListNode(-101, list2);
        while (list1->next != nullptr && list2->next != nullptr)
        {
            if (list1->val <= list2->next->val &&
                list1->next->val >= list2->next->val)
            {
                ListNode *tmp = list2->next;
                list2->next = tmp->next;
                tmp->next = list1->next;
                list1->next = tmp;
                list1 = list1->next;
            }
            else if (list1->next->val < list2->next->val)
                list1 = list1->next;
        }
        while (list2->next != nullptr)
        {
            ListNode *tmp = list2->next;
            list2->next = tmp->next;
            tmp->next = list1->next;
            list1->next = tmp;
        }

        return list1;
    }
};

/*
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = new ListNode();
        ListNode *current = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                current->next = new ListNode(list1->val);
                current = current->next;
                list1 = list1->next;
            }
            else
            {
                current->next = new ListNode(list2->val);
                current = current->next;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr)
        {
            current->next = new ListNode(list1->val);
            current = current->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2 = list2->next;
        }
        return ans->next;
    }
};
*/

int main()
{

    return 0;
}