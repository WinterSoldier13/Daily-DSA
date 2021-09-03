#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
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

// Function to remove duplicates from the linked list
// root: root of the linked list
Node* deleteMid(Node* head)
{
    Node* temp = head;
    int l = 0;

    while (temp)
    {
        l++;
        temp = temp->next;
    }
    temp = head;

    if(l%2 == 0)
    {
        int count = l/2 - 1;
        while (count--)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        
    }
    else
    {
        int count = (l+1)/2 - 2;
        while (count--)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    return head;
    
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    return 1;
}