#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tup tuple<int, int>


class Solution
{
public:

    ListNode* reverseList(ListNode* node)
    {
        ListNode* ptr1 = node;
        ListNode* ptr2 = node;
        ListNode* temp = node->next;
        int count = 0;

        while(temp!=NULL)
        {
            ptr2 = temp;
            temp = ptr2->next;
            ptr2->next = ptr1;
            if(count == 0)
            {
                ptr1->next = NULL;
                count++;
            }
            ptr1 = ptr2;
        }
        return ptr2;
    }
    void printList(ListNode* node)
    {
        while (node)
        {
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
        
    }
    void reorderList(ListNode *head)
    {
        ListNode *ptr = head;
        int l = 0;

        while (ptr != NULL)
        {
            l++;
            ptr = ptr->next;
        }
        if(l<=2)
        {
            return ;
        }
        ptr = head;
        int midDist;
        if (l % 2 == 0)
        {
            midDist = l / 2;
        }
        else
        {
            midDist = (l + 1) / 2;
        }
        while (midDist--)
        {
            ptr = ptr->next;
        }
        ListNode *oneLessThanPtr = head;

        while (oneLessThanPtr->next != ptr)
        {
            oneLessThanPtr = oneLessThanPtr->next;
        }

        oneLessThanPtr->next = reverseList(ptr);

        printList(head);
        
        ptr = oneLessThanPtr->next;
        

        oneLessThanPtr->next = NULL;


        ListNode* ptr1 = head;
        ListNode* ptr2 = ptr;
        ListNode* temp1 = ptr1->next;
        ListNode* temp2 = ptr2->next;

        while(temp1!=NULL and temp2!=NULL)
        {
            ptr1->next = ptr2;
            ptr2->next = temp1;
            ptr1 = temp1;
            ptr2 = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(ptr2!=NULL)
        {
            ptr1->next = ptr2;
            ptr2->next = temp1;
        }

    }
};