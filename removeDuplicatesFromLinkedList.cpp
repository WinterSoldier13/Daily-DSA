#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node *root)
{
    int l = 0;
    
    Node* temp = root;
    while(temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    if(l == 0 or l == 1)
    {
        return root;
    }

    Node* ptr1 = root;
    Node* ptr2 = root->next;

    while(ptr2!=NULL)
    {
        if(ptr2->data == ptr1->data)
        {
            ptr2 = ptr2->next;
        }
        else
        {
            ptr1->next = ptr2;
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        
    }
    ptr1->next = ptr2;
    return root;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    return 1;
}