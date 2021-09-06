class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int val = 0, ListNode *p = nullptr, ListNode *n = nullptr) : val(val), next(n), prev(p) {}
    };
    ListNode *preHead;
    ListNode *tail;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        preHead = new ListNode();
        tail = new ListNode();
        preHead->next = tail;
        tail->prev = preHead;
        size = 0;
    }
    ListNode *getNode(int index) const
    {
        ListNode *cur = preHead;
        while (index-- >= 0 && cur != tail)
        {
            cur = cur->next;
        }
        return cur;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) const
    {
        ListNode *cur = getNode(index);
        if (cur == preHead || cur == tail)
            return -1;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        ListNode *cur = new ListNode(val, preHead, preHead->next);
        preHead->next->prev = cur;
        preHead->next = cur;
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        ListNode *cur = new ListNode(val, tail->prev, tail);
        tail->prev->next = cur;
        tail->prev = cur;
        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        ListNode *cur = getNode(index);
        if (cur == preHead)
            return addAtHead(val);
        if (cur == tail)
            return addAtTail(val);
        ListNode *toAdd = new ListNode(val, cur->prev, cur);
        cur->prev->next = toAdd;
        cur->prev = toAdd;
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
            return;
        ListNode *removed = getNode(index);
        removed->prev->next = removed->next;
        removed->next->prev = removed->prev;
        delete removed;
        --size;
    }
};