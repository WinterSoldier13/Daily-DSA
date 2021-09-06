#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<double, int>

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

#define ListNode Node
#define val data
ListNode *merge(ListNode *l1, ListNode *l2)
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

Node *mergeSort(Node *head)
{
    // your code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = slow->next;
    slow->next = NULL;

    return merge(mergeSort(head), mergeSort(newHead));
}
