class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        while(ptr2!=NULL)
        {
            if(ptr1->val == ptr2->val)
            {
                if(ptr2->next == NULL)
                {
                    break;
                }
                ptr2 = ptr2->next;
            }
            else
            {
                ptr1->next = ptr2;
                ptr1 = ptr1->next;
            }
        }
        if(ptr2!=NULL and ptr1!=NULL and ptr1->val == ptr2->val)
        {
            ptr1->next = NULL;
        }
        return head;
    }
};