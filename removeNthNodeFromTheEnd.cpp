/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
            return head;
        if(head->next == NULL and n==1)
        {
            return NULL;
        }
        
        ListNode* slow = head;
        int l =0;
        while(slow!=NULL)
        {
            l++;
            slow = slow->next;
        }
        slow = head;
        if(l==n)
        {
            head = head->next;
            return head;
        }
        ListNode* fast = head;
        while(--n)
        {
            fast= fast->next;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast = head;
        while(fast->next!=slow)
        {
            fast = fast->next;
        }
        
        
        fast->next = slow->next;
        return head;
        
    }
};