class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr= head,*prev = head;
        while(curr){
            if(curr->val ==val && prev->val ==val){
                prev=prev->next;
                head = head->next;
                curr->next=nullptr;
                delete curr;
                curr = prev;
                continue;
            }
            else if(curr->val==val){
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;
                curr = prev;
            }
            
            prev = curr;5 
            curr=curr->next;
        }
        return head;

    }
};