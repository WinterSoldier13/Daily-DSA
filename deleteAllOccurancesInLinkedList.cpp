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

/*You are required to complete below method*/
Node *deleteAllOccurances(Node *head, int x)
{
    if (head == NULL)
    {
        return head;
    }
    while (head->data == x)
    {
        head = head->next;
    }

    Node *prev = head;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
