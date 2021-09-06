#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

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

Node* deleteK(Node* head, int k)
{
    int count = 1;
    Node* temp = head;
    Node* prev = temp;
    if (k == 0 || head == NULL)
        return head;
    if (k == 1)
        return NULL;
    while (temp != NULL)
    {
        if (count % k == 0)
        {
            prev->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return head;
}