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
        ListNode *ans = list1;
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
            list1 = list1->next;
        }
        return ans->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        int n = lists.size();
        ListNode *ans = mergeKLists(lists, 0, n - 1);
        return ans;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end)
    {
        int n = end - start + 1;
        ListNode *ans;
        if (lists.size() == 0)
            return nullptr;
        if (n == 1)
        {
            ans = lists[start];
            return ans;
        }
        if (n == 2)
        {
            ListNode *l1 = lists[start], *l2 = lists[end];
            ans = mergeTwoLists(l1, l2);
            return ans;
        }
        int mid = (start + end) / 2;
        ListNode *l1 = mergeKLists(lists, start, mid);
        ListNode *l2 = mergeKLists(lists, mid + 1, end);
        ans = mergeTwoLists(l1, l2);
        return ans;
    }
};

/*
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;

        ListNode *head = new ListNode();
        ListNode *temp = head;

        while (true)
        {
            int low = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if ((lists[low] != nullptr &&
                     (lists[i] != nullptr && lists[low]->val > lists[i]->val)) ||
                    (lists[low] == nullptr && lists[i] != nullptr))
                    low = i;
            }
            if (lists[low] == nullptr)
                break;
            temp->next = lists[low];
            temp = temp->next;
            lists[low] = lists[low]->next;
        }

        return head->next;
    }
};
*/
int main()
{
    int n;
    cin >> n;
    vector<ListNode *> v(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        ListNode *head = new ListNode();
        ListNode *current = head;
        for (int j = 0; j < c; j++)
        {
            int tmp;
            cin >> tmp;
            current->next = new ListNode(tmp);
            current = current->next;
        }
        v[i] = head->next;
        // cout << head->next->val << '\n';
    }

    ListNode *head = Solution().mergeKLists(v);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}