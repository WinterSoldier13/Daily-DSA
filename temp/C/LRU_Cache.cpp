struct DLL
{
    int key;
    int val;
    DLL* prev;
    DLL* next;
    DLL(int k,int x)
    {
        key = k;
        val = x;
        prev = next = NULL;
    }
};

void deleteNode(DLL* node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
}
DLL* insertNode(DLL* head, int key,  int val)
{
    DLL* node = new DLL(key,val);
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    return node;
}

class LRUCache {
public:
    unordered_map<int, DLL*> hashmap;
    DLL* head;
    DLL* tail;
    int cap;
    LRUCache(int c) 
    {
        head = new DLL(INT_MIN,INT_MIN);
        tail = new DLL(INT_MAX,INT_MAX);
        head->next = tail;
        tail->prev = head;
        cap = c;
    }

    int get(int key) 
    {
        if(hashmap.find(key) != hashmap.end())
        {
            int val = hashmap[key]->val;
            deleteNode(hashmap[key]);
            hashmap[key] = insertNode(head, key, val);
            return val;
        }   
        return -1;
    }

    void set(int key, int val) 
    {
         if(hashmap.find(key) != hashmap.end())
        {
            deleteNode(hashmap[key]);
            hashmap[key] = insertNode(head,key, val);
        }   
        else
        {
            hashmap[key] = insertNode(head, key, val);
            if(hashmap.size() >cap)
            {
                int d = tail->prev->key;
                deleteNode(tail->prev);
                hashmap.erase(d);
            }
        }
    }
};
