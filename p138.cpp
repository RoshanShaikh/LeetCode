#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        if (!head->next)
            return new Node(head->val);

        Node *originalNode = head;
        Node *cloneList = new Node(originalNode->val);

        cloneList->next = originalNode->next;
        originalNode->next = cloneList;
        originalNode = cloneList->next;

        Node *cloneNode = cloneList;

        while (originalNode)
        {
            cloneNode = new Node(originalNode->val);
            cloneNode->next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneList;

        while (originalNode)
        {
            if (originalNode->random)
                originalNode->next->random = originalNode->random->next;
            originalNode = originalNode->next->next;
        }

        originalNode = head;
        cloneNode = cloneList;

        while (originalNode)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if (originalNode)
            {
                cloneNode->next = originalNode->next;
                cloneNode = cloneNode->next;
            }
        }

        return cloneList;
    }
};

int main()
{

    return 0;
}