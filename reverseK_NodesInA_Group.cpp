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
        
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
         if(head == NULL)
    {
        return head;
    }
    int l=0;

    ListNode* temp = head;
    while(temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    if(l<k)
    {
        return head;
    }
    
        if(l==k)
        {
            return reverseList(head);
        }
    //reverse first k elements
    ListNode* ptr1 ;ListNode* ptr2;
    ListNode* slow= head;
    ptr1 = head;
    ListNode* fast = head->next;
    
    for(int i=1;i<k;i++)
    {
        temp = fast;
        fast = fast->next;
        temp->next = slow;
        slow = temp;
    }
    ListNode* prevHead = slow;
    ptr2 = slow;
    head = slow;
    for(int i =0;i<k-1;i++)
    {
        slow = slow->next;
    }
    ptr1 = slow;

    for(int i=0;i<(int)(l-k)/k;i++)
    {
        slow = fast;
        prevHead = slow;
        fast = slow->next;

        for(int i=1;i<k;i++)
        {
            temp = fast;
            fast = fast->next;
            temp->next = slow;
            slow = temp;
        }
        ptr1->next = slow;
        for(int i =0;i<k-1;i++)
        {
            slow = slow->next;
        }
        ptr1 = slow;
    }
    if(fast!=NULL)
    {
        ptr1->next = fast;
    }
        else
    {
        ptr1->next = NULL;
    }
    return head;
    }
};