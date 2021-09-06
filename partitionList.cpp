#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tup tuple<int, int>

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tup tuple<int, int>


class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *firstElementGreaterThanX = head;
        int l = 0;
        ListNode* length = head;
        while(length!=NULL)
        {
            l++;
            length = length->next;
        }
        if(l==1)
        {
            return head;
        }
        if (head == NULL)
        {
            return NULL;
        }

        while (firstElementGreaterThanX != NULL)
        {
            if (firstElementGreaterThanX->val >= x)
            {
                break;
            }
            firstElementGreaterThanX = firstElementGreaterThanX->next;
        }
        if(firstElementGreaterThanX == NULL)
        {
            return head;
        }

        ListNode *oneElementLessThanFirstElementGreaterThanX = head;

        while (oneElementLessThanFirstElementGreaterThanX != firstElementGreaterThanX and oneElementLessThanFirstElementGreaterThanX->next != firstElementGreaterThanX)
        {
            oneElementLessThanFirstElementGreaterThanX = oneElementLessThanFirstElementGreaterThanX->next;
        }

        if (firstElementGreaterThanX == head)
        {
            ListNode * ptr = head;

            ListNode* before = new ListNode(-1);
            ListNode* beforeHead = before;
            ListNode* after = new ListNode(-1);
            ListNode* afterHead = after;
            while(ptr!=NULL)
            {
                if(ptr->val <x)
                {
                    before->next = ptr;
                    before = before->next;
                }
                else
                {
                    after->next = ptr;
                    after = after->next;
                }
                ptr = ptr->next;
            }
            after->next = NULL;
            before->next = afterHead->next;

            beforeHead= beforeHead->next;
            return beforeHead;
        }

        ListNode *ptr = firstElementGreaterThanX->next;
        ListNode *temp = firstElementGreaterThanX;
        while (ptr != NULL)
        {
            int val = ptr->val;

            if (val < x)
            {
                ListNode *nextEle = ptr->next;
                oneElementLessThanFirstElementGreaterThanX->next = ptr;
                ptr->next = firstElementGreaterThanX;
                oneElementLessThanFirstElementGreaterThanX = ptr;
                temp->next = nextEle;
                ptr = nextEle;
            }
            else
            {
                ptr = ptr->next;
                temp = temp->next;
            }
        }
        return head;
    }
};