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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        
        int l = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=NULL)
        {
            l++;
            slow = slow->next;
        }
        if(l==1)
            return head;
        if(l == 2)
        {
            slow = head;
            fast = slow->next;
            fast->next = slow;
            slow->next = NULL;
            return fast;
        }
        slow = head;
        fast = slow->next;
        
        while(fast!=NULL)
        {
            ListNode* temp = fast;
            fast = fast->next;
            temp->next = slow;
            slow = temp;
        }
        head = slow;
        while(l--)
        {
            slow=slow->next;
        }
        slow->next->next = NULL;
        return head;
    }
};