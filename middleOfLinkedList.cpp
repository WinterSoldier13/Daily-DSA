#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    if(head == NULL)
    {
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL and fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
    
}
