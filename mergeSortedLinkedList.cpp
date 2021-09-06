

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *h1 = l1;
        ListNode *h2 = l2;

        ListNode *head = new ListNode(0);

        ListNode *track = head;

        while (h1 != NULL and h2 != NULL)
        {
            if (h1->val <= h2->val)
            {
                track->next = h1;
                h1 = h1->next;
            }
            else
            {
                track->next = h2;
                h2 = h2->next;
            }
            track = track->next;
        }
        if (h1 != NULL)
        {
            track->next = h1;
        }
        if (h2 != NULL)
        {
            track->next = h2;
        }
        head = head->next;

        return head;
    }
};