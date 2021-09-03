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

ListNode *detectCycle(ListNode *head) 
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = slow;
    bool loop = false;

    while(fast!=NULL and fast->next!=NULL and slow!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            loop = true;
            cout<<slow->val<<endl;
            
            slow = head;
            
            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        if(loop)
        {
            
            break;
        }
    }
    cout<<slow->val<<endl;
    if(!loop)
    {
        return NULL;
    }
    return slow;
}
};