/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// USING O(n) extra space
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_set<ListNode*> hashset;
        while(headA!=NULL)
        {
            hashset.insert(headA);
            headA = headA->next;
        }
        
        while(headB!=NULL)
        {
            if(hashset.find(headB)!=hashset.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
        
    }
};