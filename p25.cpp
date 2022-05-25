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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *current = head;
        vector<int> v;
        while (current != nullptr)
        {
            v.push_back(current->val);
            current = current->next;
        }
        for (int i = 0; i < v.size(); i += k)
        {
            if(i+k-1 < v.size())
                reverse(v, i, i + k - 1);
        }
        
        
        current = head;
        for (auto &&i : v)
        {
            current->val = i;
            current = current->next;
        }
        return head;
    }
    void reverse(vector<int> &v, int start, int end)
    {
        while (start < end)
        {
            swap(v[start++], v[end--]);
        }
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
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
    ListNode *ans = Solution().reverseKGroup(head, k);
    while (ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}