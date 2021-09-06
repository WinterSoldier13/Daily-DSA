/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)
        {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow!= NULL and fast!=NULL and slow->val == fast->val)
            {
                return true;
            }
        }
        return false;
    }
};