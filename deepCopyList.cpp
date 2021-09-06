#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> hashmap;

        Node* temp = head;

        while(temp!=NULL)
        {
            Node* node = new Node(temp->val);
            hashmap[temp] = node;
            temp = temp->next;
        }

        temp = head;
        while (temp!=NULL)
        {
            hashmap[temp]->random = hashmap[temp->random];
            temp = temp->next;
        }
        temp = head;
        while (temp!=NULL)
        {
            hashmap[temp]->next = hashmap[temp->next];
            temp = temp->next;
        }
        return hashmap[head];
        
    }
};