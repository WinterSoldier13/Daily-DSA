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

Node *merge(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
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
