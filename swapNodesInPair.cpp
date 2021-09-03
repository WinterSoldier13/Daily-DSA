
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        int l = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            l++;
        }
        if (l == 0 or l == 1)
        {
            return head;
        }
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *prev = dummyNode;
        ListNode *curr = head;

        while (curr != NULL and curr->next != NULL)
        {
            ListNode *mark1 = curr->next;
            ListNode *mark2 = curr->next->next;

            curr->next->next = curr;
            curr->next = mark2;
            prev->next = mark1;

            prev = curr;
            curr = mark2;
        }

        return dummyNode->next;
    }
};
